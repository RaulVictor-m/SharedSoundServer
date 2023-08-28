#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

#include "audio_interface.h"
#include "socket_interface.h"


#include "log.h"


int main(void)
{

	ss_audio *audio = ss_audio_connect();
	

	ss_socket server = ss_socket_init();
	ss_socket_conn conn = ss_socket_conn_acpt(server);
	
	char audio_buffer[1024];
	while(1)
	{



		int read = ss_audio_read(audio, audio_buffer, 1024);
		if(read == 0)
		{
			int sent = ss_socket_conn_write(conn, audio_buffer, sizeof(audio_buffer));
			if(sent < 0)
			{
				ss_LOG("Connection failed");
				exit(0);
			}


		}
		else
		{
			ss_LOG("failed on pulse read");
			exit(0);
		}

		

	}
	
	
	

	ss_socket_conn_close(conn);
	ss_socket_stop(server);
	ss_audio_clean(audio);
}



#include "log.h"
#include "socket_interface.h"


static struct sockaddr_in address;

ss_socket ss_socket_init()
{
	int server_descriptor;
	

	int opt = 1;
	
	//CREATE SOCKET
	server_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	if(server_descriptor < 0)
	{
		ss_LOG("Fail to create Socket");
		return -1;
	}
	
	//SET OPT
	if(setsockopt(server_descriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		ss_LOG("Fail to create Socket");
		return -1;
	}

	//BIND SERVER
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8089);
	if(bind(server_descriptor, (struct socketaddr*)&address, sizeof(address)) < 0)
	{
		ss_LOG("Fail to bind Socket");
		return -1;
	}

	//LISTEN AND SERVE
	if(listen(server_descriptor, 3) < 0)
	{
		ss_LOG("Fail to listen and serve Socket");
		return -1;
	}


	return server_descriptor;
}

ss_socket_conn ss_socket_conn_acpt(ss_socket server)
{
	ss_LOG("LISTENING FOR CONNECTIONS \n");

	int addrlen = sizeof(address);
	int new_conn = accept(server,(struct socketaddr*)&address, (socklen_t*)&addrlen);

	if((new_conn < 0))
	{
		perror("socket failed");
		exit(EXIT_FAILURE);

		ss_LOG("connection not stabilished ");
		return -1;
	}

	ss_LOG("connection stabilished");
	return new_conn;
}

int ss_socket_conn_write(ss_socket_conn conn, void *data, size_t size)
{
	return send(conn, data, size, 0);
}

int ss_socket_conn_read(ss_socket_conn conn, void *data, size_t size)
{
	return read(conn, data, size);
}

void ss_socket_conn_close(ss_socket_conn conn)
{
	close(conn);
}

void ss_socket_stop(ss_socket server)
{
	shutdown(server, SHUT_RDWR);
}

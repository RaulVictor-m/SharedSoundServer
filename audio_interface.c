#include "audio_interface.h"

ss_audio* ss_pulse_connect()
{
	pa_simple *pulse;
	pa_sample_spec format;

	format.format = PA_SAMPLE_S16NE;
	format.channels = 1;
	format.rate = 44100;

	pulse = pa_simple_new(	NULL,
							ss_APP_NAME,		//name
							PA_STREAM_RECORD,
							NULL,
							" ",				//description
							&format,
							NULL,
							NULL,
							NULL
						 	);
	if(pulse == NULL)
	{
		printf("broken pulse\n");fflush(stdout);
		exit(0);
	}
	return pulse;
}

bool ss_pulse_read(ss_audio *pulse, char *data, size_t num_bytes)
{
	return pa_simple_read(pulse, data, num_bytes, NULL);
}

void ss_pulse_clean(pa_simple *pulse)
{
	pa_simple_free(pulse);
}

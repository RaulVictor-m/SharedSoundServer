#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <pulse/error.h>
#include <pulse/simple.h>
#include <unistd.h>
#include <stdbool.h>

#include <assert.h>


#define LINUX_PULSE
#ifdef 	LINUX_PULSE
#define ss_audio_connect 	ss_pulse_connect
#define ss_audio_clean 		ss_pulse_clean
#define ss_audio_read 		ss_pulse_read

typedef pa_simple    		ss_audio;

ss_audio* 	ss_pulse_connect	();
bool 		ss_pulse_read		(ss_audio *pulse, char *data, size_t num_bytes);
void 		ss_pulse_clean		(ss_audio *pulse);
#endif

#define ss_APP_NAME "SharedSound"

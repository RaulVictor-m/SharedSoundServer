#include "log.h"

void log(const char *str)
{
	printf(str);
	fflush(stdout);
}

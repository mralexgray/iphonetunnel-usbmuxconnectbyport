
#include <stdarg.h>
#include <stdio.h>
#include <libmd/libMobiledevice.h>
#include "options.h"

const char* sev2str(LOG_LEVEL severity) {

	return severity == LOG_FATAL ? "FATAL" :
         severity == LOG_ERROR ? "ERROR" :
         severity == LOG_INFO  ? "INFO"  :
         severity == LOG_DEBUG ? "DEBUG" : "!UNKNOWN!";
}

void LogPrintf(LOG_LEVEL severity, const char* fmt...) {

	if (severity > g_logSeverity) return;

	va_list valist; va_start(valist, fmt);

	printf("[%s] ", sev2str(severity)); vprintf(fmt, valist); printf("\n"); fflush(stdout);

	va_end(valist);
}

#ifndef KPME_SV_H
#define KPME_SV_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#ifdef __unix
	#define PLATFORM_UNIX
	#include <unistd.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#include <sys/socket.h>
#endif

#ifdef _WIN32
	#define PLATFORM_WINDOWS
	#include <winsock2.h>
#endif

#endif

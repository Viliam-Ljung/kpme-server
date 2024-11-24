#include <kpme_sv.h>

#ifdef PLATFORM_UNIX

int handle_client(int clientfd, void (*handler)(int)) {
	int pid;

	pid = fork();
	if(pid == 0) 
		(*handler)(clientfd);
	else
		return pid;
}

#endif

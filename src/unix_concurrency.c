#include <kpme_sv.h>

#ifdef PLATFORM_UNIX

void handle_client(int clientfd, void (*handler)(int)) {
	int pid;

	pid = fork();
	if(pid == 0) 
		(*handler)(clientfd);
	if(pid < 0)
		printf("something went wrong when starting a client thread\n");
}

#endif

#include <kpme_sv.h>

void sock_init(int, struct sockaddr_in*);

void sock_init(int sockfd, struct sockaddr_in* sv_addr) {
	int err;

	sv_addr->sin_family = AF_INET;
	sv_addr->sin_port = htons(7070);
	sv_addr->sin_addr.s_addr = htonl(INADDR_ANY);

	err = bind(sockfd, (struct sockaddr*)sv_addr, sizeof(struct sockaddr_in));
	if(err != 0) {
		printf("no bind :(\n");
		exit(1);
	}

	err = listen(sockfd, 5);
	if(err != 0) {
		printf("no listen :(\n");
		exit(1);
	}
} 

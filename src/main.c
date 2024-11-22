#include <kpme_sv.h>

void sock_init(int, struct sockaddr_in*);
void handle_client(int);

int main(int argc, char** argv) {
	struct sockaddr_in sv_addr, cli_addr;
	unsigned int len;
	int sockfd, connfd, err;

	len = 0;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1) {
		printf("fuck you\n");
		exit(1);
	}

	sock_init(sockfd, &sv_addr);

	connfd = accept(sockfd, (struct sockaddr*)&cli_addr, &len);

	handle_client(connfd);	
}

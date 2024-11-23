#include <kpme_sv.h>

void sock_init(int, struct sockaddr_in*);
void handle_client(int);

void wsa_startup();

int main(int argc, char** argv) {
	struct sockaddr_in sv_addr, cli_addr;
	unsigned int len;
	int sockfd, connfd, err;

	len = sizeof(struct sockaddr_in);

	wsa_startup();

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == SOCKET_ERROR) {
		printf("Couldn't create socket!\n");
		exit(1);
	}

	sock_init(sockfd, &sv_addr);

	connfd = accept(sockfd, (struct sockaddr*)&cli_addr, &len);

	handle_client(connfd);
}

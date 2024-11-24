#include <kpme_sv.h>

void sock_init(int, struct sockaddr_in*);
int handle_client(int, void (*)(int));

void wsa_startup();

void hand(int fd) {
	char buffer[1024];
	int len;

	for(int i=0;i<1024;i++)
		buffer[i] = 0;

	while(1) {
		len = recv(fd, buffer, 1024, 0);

		printf("%s\n", buffer);

		write(fd, "hello", 5);

		if(buffer[0]=='H') {
			break;
		}
	}
	printf("client thread ended\n");
}

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
	
	while(1) {
		connfd = accept(sockfd, (struct sockaddr*)&cli_addr, &len);

		handle_client(connfd, &hand);
	}
}

#include <kpme_sv.h>

void sock_init(int, struct sockaddr_in*);
void handle_client(int clientfd, void (*handler)(int));

void wsa_startup();

void hand(int clientfd) {
	printf("Client thread started for (%d)\n", clientfd);

	char buffer[1024];
	int len;

	for (int i = 0; i < 1024; i++) {
		buffer[i] = 0;
	}

	while(1) {
		len = recv(clientfd, buffer, 1024, 0);
		if (len == -1) {
			printf("[ERROR]: (%d)\n", WSAGetLastError());
			break;
		}
		if (len == 0) {
			printf("Client %d disconnected!", clientfd);
			break;
		}

		printf("RECV %d %d\n", clientfd, len);
		// printf("%s\n", buffer);

		// send(clientfd, "hello", 5, 0);

		if (buffer[0] == 'H') break;
	}
	printf("Client thread ended\n");
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
		printf("Client accepted with id: (%d)\n", connfd);
		handle_client(connfd, &hand);
	}
}

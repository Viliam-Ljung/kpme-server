#include <kpme_sv.h>

void handle_sv(int svsock);

void sock_init(int, struct sockaddr_in*);
void handle_client(int);

int main(int argc, char** argv) {
	struct sockaddr_in sv_addr, cli_addr;
	unsigned int len;
	int sockfd, connfd, err;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1) {
		printf("fuck you\n");
		exit(1);
	}

	sock_init(sockfd, &sv_addr);

	connfd = accept(sockfd, (struct sockaddr*)&cli_addr, &len);

	handle_client(connfd);	

	close(connfd);
	close(sockfd);
}

void handle_client(int clifd) {
	char buffer[1024];
	int len;
	
	len = read(clifd, buffer, 1024);

	write(1, buffer, len);

	write(clifd, "hello", 5);
}

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

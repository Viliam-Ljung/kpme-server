#include <kpme_sv.h>

void handle_client(int clifd) {
	char buffer[1024];
	int len;

	len = recv(clifd, buffer, sizeof(buffer), 0);

	send(clifd, "hello", 5, 0);

	printf("%s\n", buffer);
}

#include <kpme_sv.h>

#ifdef PLATFORM_WINDOWS
#include <windows.h>

typedef struct {
    int clientfd;
    void (*handler)(int);
} ThreadArgs;

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
    ThreadArgs* args = (ThreadArgs*)lpParam;
    args->handler(args->clientfd);

    free(args);
    return 0;
}

void handle_client(int clientfd, void (*handler)(int)) {
    ThreadArgs* args = (ThreadArgs*)malloc(sizeof(ThreadArgs));
    if (args == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    args->clientfd = clientfd;
    args->handler = handler;

    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, args, 0, NULL);
    if (thread) {
        printf("Successfully created thread!\n");
    }
}

#endif
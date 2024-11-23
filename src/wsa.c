#include <kpme_sv.h>

void wsa_startup() {
    #ifdef PLATFORM_WINDOWS
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != NO_ERROR) {
            printf("WSAStartup failed with error: %d\n", result);
            exit(1);
        }
    #endif
}
// https_server.c
// HTTPS support for Sentinel Web UI (OpenSSL-based, stub)

#include "https_server.h"
#include <stdio.h>

int start_https_server(int port, const char *cert_file, const char *key_file) {
    printf("[HTTPS] Starting HTTPS server on port %d (stub)\n", port);
    // TODO: Implement HTTPS server using OpenSSL
    return 0;
}

// sentinel_server.c
// Lightweight HTTP server for Project Sentinel Web UI
// Initial version: serves a static HTML dashboard and provides endpoints for firewall management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 4096

const char *dashboard_html = "<html><head><title>Project Sentinel</title></head><body><h1>Sentinel Firewall Web UI</h1><p>Status: Running</p></body></html>";

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read <= 0) {
        close(client_fd);
        return;
    }
    buffer[bytes_read] = '\0';
    // Simple GET / handler
    if (strncmp(buffer, "GET / ", 7) == 0 || strncmp(buffer, "GET /HTTP", 8) == 0) {
        char response[BUFFER_SIZE * 2];
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %zu\r\n\r\n%s",
                 strlen(dashboard_html), dashboard_html);
        write(client_fd, response, strlen(response));
    } else {
        const char *not_found = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
        write(client_fd, not_found, strlen(not_found));
    }
    close(client_fd);
}

void start_server() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    int opt = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Sentinel Web UI running on http://localhost:%d\n", PORT);
    while (1) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) continue;
        handle_client(client_fd);
    }
}

void sigint_handler(int sig) {
    printf("\nShutting down Sentinel Web UI...\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);
    start_server();
    return 0;
}

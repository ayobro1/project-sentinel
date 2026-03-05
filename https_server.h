// https_server.h
// HTTPS support for Sentinel Web UI (OpenSSL-based, stub)

#ifndef HTTPS_SERVER_H
#define HTTPS_SERVER_H

int start_https_server(int port, const char *cert_file, const char *key_file);

#endif

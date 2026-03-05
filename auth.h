// auth.h
// User authentication for Sentinel Web UI

#ifndef AUTH_H
#define AUTH_H

int authenticate_user(const char *username, const char *password);
void set_user_password(const char *username, const char *password);

#endif

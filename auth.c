// auth.c
// User authentication for Sentinel Web UI

#include "auth.h"
#include <string.h>
#include <stdio.h>

#define MAX_USERS 4
#define MAX_USER_LEN 32
#define MAX_PASS_LEN 64

static char users[MAX_USERS][MAX_USER_LEN] = {"admin"};
static char passwords[MAX_USERS][MAX_PASS_LEN] = {"sentinel"};

int authenticate_user(const char *username, const char *password) {
    for (int i = 0; i < MAX_USERS; ++i) {
        if (strcmp(users[i], username) == 0 && strcmp(passwords[i], password) == 0) {
            return 1;
        }
    }
    return 0;
}

void set_user_password(const char *username, const char *password) {
    for (int i = 0; i < MAX_USERS; ++i) {
        if (strcmp(users[i], username) == 0) {
            strncpy(passwords[i], password, MAX_PASS_LEN-1);
            passwords[i][MAX_PASS_LEN-1] = '\0';
            return;
        }
    }
}

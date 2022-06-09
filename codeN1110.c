#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20
#define MAX_USERNAME_LEN 20

struct User {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int uid;
};

struct User usersDb[3] = {
        {.username = "admin", .password = "jrAz+"},
        {.username = "userA", .password = "ocAr6"},
        {.username = "userB", .password = "idMf("},
};


const char secret[8] = {11, 22, 44, 19, 69, 30, 90, 14};

char *encrypt(char *toEncrypt, int size) {
    int i;
    for (i = 0; i < size; i++)
        toEncrypt[i] ^= secret[i];

    printf("toEncrypt: %s\n",toEncrypt);
    return toEncrypt;

}

char *decrypt(char *toDecrypt, int size) {
    int i;
    for (i = 0; i < size; i++)
        toDecrypt[i] ^= secret[i];
    //printf("toDecrypt: %s\n",toDecrypt);
    return toDecrypt;

}

int checkValidUserName(char *username) {
    for (int i = 0; i < 3; i++) {
        if (strncmp(username, usersDb[i].username,MAX_USERNAME_LEN) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkValidPassword(char *password) {
    for (int i = 0; i < 3; i++) {
        if (strncmp(password, decrypt(usersDb[i].password, strlen(usersDb[i].password)), MAX_PASSWORD_LEN) == 0) {
            return 1;
        }
    }
    return 0;
}


int checkCredentials(char *username, char *password) {
    if (checkValidUserName(username)) {
        if (checkValidPassword(password)) {
            printf("Welcome %s\n", username);
            return 1;
        } else {
            printf("%s", "Password is invalid\n");
            return 0;
        }
    } else {
        printf("%s", "Username is invalid\n");
    }
    return 1;
}

int main(int argc, char **argv) {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    printf("Enter username:");
    scanf("%19s", username);
    printf("Enter password:");
    scanf("%19s", password);
    checkCredentials(username, password);
}

// strcmp(password, decrypt(usersDb[i].password, strlen(usersDb[i].password))) == 0) {
// strncmp(password, usersDb[i].password, MAX_PASSWORD_LEN) == 0) {

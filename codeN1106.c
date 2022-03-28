#include <stdio.h>
#include <string.h>

#define USERNAME_DB "usernames.dat"
#define MAX_LEN 8
#define FAILED 0
#define SUCCESS 1

int checkUsernameLength(char *username) {
    if (username == NULL) {
        return -1;
    }
    if (strlen(username) > MAX_LEN) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    umask(0);
    fp = fopen(USERNAME_DB, "a");

    switch (checkUsernameLength(argv[1])) {
        case FAILED:
            printf("Username too long");
            return (0);
        case SUCCESS:
            break;
    }

    if (fp) {
        fprintf(fp, "%s\n", argv[1]);
        printf("%s\n", "username added to file");
    }
    return (0);
}

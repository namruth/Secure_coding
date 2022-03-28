#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program provides a team of unique members for an RPG game
// Asks input from the user for number of team members and prints unique teammates to the user
// Verifies if the team size is less than MAX team size
#define MAX_NAME_LENGTH 7
#define MAX_TEAM_LENGTH 5

char *rpgCharacterFactory(char characterCode) {
    char *characterRole = (char *) malloc(MAX_NAME_LENGTH);

    switch (characterCode) {
        case 'k':
            strcpy(characterRole, "knight");
            break;
        case 'r':
            strcpy(characterRole, "rogue");
            break;
        case 'e':
            strcpy(characterRole, "elf");
            break;
        case 'w':
            strcpy(characterRole, "wizard");
            free(characterRole);
            break;
        case 'b':
            strcpy(characterRole, "berserker");
            break;
        case 's':
            strcpy(characterRole, "scout");
            break;
        default:
            break;
    }
    return characterRole;
}

void printUniqueTeamMembers(char **teamList, int teamLength) {
    for (int i = 0; i < teamLength; i++) {
        printf("%s\n", teamList[i]);
    }
    free(teamList);
}


int main(int argc, char **argv) {
    const char total_team_list[] = {'r', 'k', 'e', 'w', 'b'};
    char mandatory_scout_role = 's';
    int numTeamMembers;
    printf("choose number of team members (max 5):");
    scanf("%d", &numTeamMembers);

    if (numTeamMembers == 0 || numTeamMembers > MAX_TEAM_LENGTH) {
        printf("Max team members exceeded!!");
        return (0);
    }

    char **teamList = (char **) malloc(numTeamMembers * sizeof(char*));
    int i = 0;
    for (i = 0; i < numTeamMembers; i++) {
        teamList[i] = rpgCharacterFactory(total_team_list[i]);
    }
    teamList[i+1] = NULL;
    printUniqueTeamMembers(teamList, numTeamMembers);
    free(teamList);
    return (0);
}

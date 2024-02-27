#include <stdio.h>

char board[3][3] = { {'X', ' ', ' '}, {'X', 'O', ' '}, {'X', ' ', 'O'} };

void printboard();

int main() {
    char CurrentGo = 'X', UserName[50];
    int y, x;


    //Welcome User and get user name
    printf("Welcome to X's and O's. Please enter your username: ");
    fgets(UserName, sizeof(UserName), stdin);

    //Remove Newline character from UserName
    for (int i = 0; i != sizeof(UserName); i++) {
        if (UserName[i] == '\n') {
            UserName[i] = '\0';
            break;
        }
    }

    //For loop for game. Will only run 9 times
    for (int i = 0; i != 9; i++) {
        if (CurrentGo == 'X') {
            printf("Its your go now %s, Please enter your go.\n", UserName);

            printf("Enter a letter: ");
            scanf_s("%i", &x);

            printf("Enter a Number: ");
            scanf_s("%i", &y);

            printf("%i",x);
        }

        
    }
}

void printboard() {
    printf("  1   2   3 \n");
    for (int y = 0; y != 3; y++) {
        printf("%c %c %c %c %c %c \n", 65 + y, board[y][0], 179, board[y][1], 179, board[y][2]);
        if (y != 2) {
            printf(" %c%c%c%c%c%c%c%c%c%c%c\n", 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196);
        }
    }
}
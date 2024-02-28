#include <stdio.h>
#include <stdlib.h>

char board[3][3] = { {'X', ' ', ' '}, {'X', 'O', ' '}, {'X', ' ', 'O'} };

void printboard();
int validGo();

int main() {
    char CurrentGo = 'X', UserName[50];
    int y, x;
    char y_temp;


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
            printboard();

            //While loop to continue asking untill a valid go.
            while (1 == 1) {
               printf("Enter a letter: ");
               scanf_s(" %c", &y_temp);
               
               //Stored as a char then convered to a valid cord.
               if (y_temp == 'a') {
                   y = (int)y_temp - 97;
               } else {
                   y = (int)y_temp - 65;
               }

               //Ask for the second number and convert it
               printf("Enter a Number: ");
               scanf_s("%i", &x);
               x -= 1;

               //Check if its a valid go
               int returned_value = validGo(x, y);
               
               if (returned_value == 0) {
                   board[y][x] = 'X';
                   break;
               } else if (returned_value == 1){
                   printf("Place is taken go again. Go again.\n");
               }
               else if (returned_value == 2) {
                   printf("Place is out of bounds. Go again.\n");
               }
            }
            printf("%i, %i\n", y, x);
        }
        if (CurrentGo == 'O') {
            //Computers go
        }

        
    }
}

int validGo(int x, int y) {
    return 0;
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
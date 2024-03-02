#include <stdio.h>
#include <stdlib.h>

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printboard();
int validGo();

int main() {
    char CurrentGo = 'X', UserName[50];
    int Score[2] = { 0, 0 };
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

    while (1 == 1) {
        //For loop for game. Will only run 9 times
        for (int i = 0; i != 9; i++) {
            if (CurrentGo == 'X') {
                printf("Its your go now %s, Please enter your go.\n", UserName);
                printboard();

                //While loop to continue asking untill a valid go.
                int IsValid = 2;
                while (IsValid != 0) {
                    printf("Enter your go: ");
                    scanf(" %c%i", &y_temp, &x);

                    //Stored as a char then convered to a valid cord.
                    if (y_temp >= 'a' && y_temp <= 'c') {
                        //If lowercase letter entered
                        y = (int)y_temp - 97;
                    }
                    else {
                        //If uppercase letter entered
                        y = (int)y_temp - 65;
                    }
                    //Take one away from x to make it a valid cord.
                    x -= 1;

                    //Check if its a valid go
                    IsValid = validGo(x, y);

                    //Swtich to choose response to valid go.
                    switch(IsValid){
                        case 0:
                            board[y][x] = CurrentGo;
                            break;
                        case 1:
                            printf("Place is already taken. Go again.\n");
                            break;
                        case 2:
                            printf("Place is out of bounds. Go again.\n");
                            break;
                    }
                }
                //Give control to computer. Players turn ends here
                CurrentGo = 'O';
            }
            if (CurrentGo == 'O') {
                //Computers go.
            }
            //Winning Code goes here.
        }
        printf("Would you like to play again?");
        //Printing the score and asking to play agian goes here.

        
    }
}

int validGo(int x, int y) {
    //WIP
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

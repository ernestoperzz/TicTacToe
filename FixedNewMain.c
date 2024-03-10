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
                int IsValid = 1;
                while (IsValid != 1 ) {
                    computersGo(&x, &y);
                    IsValid= validGo(x, y);
                }

            }
          char whoWon();
          if(return = 'X'){
              printf("%c won the game.\n");
          }
             if(return = 'O'){
              printf("The computer won the game.\n");
          }
        }
        printf("Would you like to play again?");
        //Printing the score and asking to play agian goes here.

        
    }
}

int validGo(int x, int y) {
     //If the go is out of bounds
    if (x > 3 || y > 3) {

        return 2;
    }

    //If the go has been said before 
    if (board[y][x] == 'X') {

        return 1;
    }
    else if (board[y][x] == 'O') {
        return 1;
    }

    //If the go is valid
    if (x >= 0 && y >= 0 && x <= 2 && y <= 2) {
        return 0;
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


char whoWon() {
   
    //rows
    for (int i = 0; i <= 2;i++) {

            if ('X' == board[i][0] && 'X' == board[i][1] && 'X'== board[i][2]) {
                
                return 'X';
            }
            if ('O' == board[i][0] && 'O' == board[i][1] && 'O' == board[i][2]) {
               
                return 'O';
            }
    }
    //columns
    for (int j = 0; j <= 2; j++) {

        if ('X' == board[0][j] && 'X' == board[1][j] && 'X' == board[2][j]) {
             
            return 'X';
        }
        if ('O' == board[0][j] && 'O' == board[1][j] && 'O' == board[2][j]) {
            
            return 'O';
        }
    }

    //Diagonals
    if ('X' == board[0][0] && 'X' == board[1][1] && 'X' == board[2][2]) {
         
        return 'X';
    }
    if ('X' == board[0][2] && 'X' == board[1][1] && 'X' == board[2][0]) {
        
        return 'X';
    }


    if ('O' == board[0][0] && 'O' == board[1][1] && 'O' == board[2][2]) {
         
        return 'O';
    }
    if ('O' == board[0][2] && 'O' == board[1][1] && 'O' == board[2][0]) {
         
        return 'O';
    }
}

//generate computers location
void computersGo(int* px, int* py) {
    int range;
    range = (2 - 0) + 1;
    srand(time(NULL));
    *px = rand() % range + 0;
    *py = rand() % range + 0;
    printf("%i", range-1);
}







#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printboard();
int validGo(int x, int y);
void computersGo(int* px, int* py);
char whoWon();


char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

int main() {
    char CurrentGo = 'X', UserName[50];
    int Score[2] = { 0, 0 }, PlayAgain = 0, FirstGo = 1;
    int y, x;
    char y_temp;
    

    //Welcome User and get user nameA2
    printf("Welcome to X's and O's. Please enter your username: ");
    fgets(UserName, sizeof(UserName), stdin);

    //Remove Newline character from UserName
    for (int i = 0; i != sizeof(UserName); i++) {
        if (UserName[i] == '\n') {
            UserName[i] = '\0';
            break;
        }
    }

    while (!PlayAgain) {
        //For loop for game. Will only run 9 times
        for (int i = 0; i != 9; i++) {
            if (CurrentGo == 'X') {
                if (FirstGo == 1){
                    printf("Its your go now %s, Please enter your go.\n", UserName);
                    FirstGo = 0;
                } else {
                    printf("The computer went in place %c%i\n", (char)(y + 'A'), x + 1);
                }

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
            } else if (CurrentGo == 'O') {
                //Start of computer go
                int IsValid = 1;
                //Run loop untill a valid move is found
                while (IsValid != 0 ) {
                    //Get random cords
                    computersGo(&x, &y);
                    //Check if valid
                    IsValid= validGo(x, y);
                }

                //Place in board
                board[y][x] = 'O';
                //Make players turn again
                CurrentGo = 'X';

            }

            char Winner = whoWon();
            if(Winner == 'X'){
                printf("%s won the game.\n",UserName);
                Score[0] += 1;
                break;
            }
            if(Winner == 'O'){
                printboard();
                printf("The computer won the game.\n");
                Score[1] += 1;
                break;
            }
        }

        if (whoWon() == ' ') printf("Nobody won!\n");


        printf("The Current score is:\n%s:\t\t%i\nComputer:\t%i\n", UserName, Score[0], Score[1]);

        char UserInput;
        int ValidInput;
        printf("Would you like to play again? (Y/N)");
        scanf(" %c", &UserInput);
        PlayAgain = 0;
        switch (UserInput){
            case 'Y':
            case 'y':
                for (int y = 0; y != 3; y++){
                    for (int x = 0; x != 3; x++){
                        board[y][x] = ' ';
                    }
                }
                FirstGo = 1;
                CurrentGo = 'X';

                break;

            default:
                printf("Thanks for playing!");
                return 0;
        }
    }
}


int validGo(int x, int y) {
     //If the go is out of bounds
    if (x >= 3 || y >= 3) {
        return 2;
    }

    //If the go has been said before 
    if (board[y][x] == 'X') {

        return 1;
    }
    else if (board[y][x] == 'O') {
        return 1;
    }

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


    return ' ';
}

//generate computers location
void computersGo(int* px, int* py) {
    int range;
    range = (2 - 0) + 1;
    srand(time(NULL));
    *px = rand() % range;
    *py = rand() % range;
}







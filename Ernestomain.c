#include <stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3] = { {'X', ' ', ' '}, {'X', 'O', ' '}, {'X', ' ', 'O'} };
int i;
void printboard();

int main() {
    char CurrentGo = 'X', UserName[50];
    int y, x;
    

    //Welcome User and get user name
    printf("Welcome to X's and O's. Please enter your username: ");
    fgets(UserName, sizeof(UserName), stdin);

    //Remove Newline character from UserName
    for ( i = 0; i != sizeof(UserName); i++) {
        if (UserName[i] == '\n') {
            UserName[i] = '\0';
            break;
        }
    }

   //4.For loop for game. Will only run 9 times
    for ( i = 0; i != 9; i++) {
        if (CurrentGo == 'X') {
            printf("Its your go now %s, Please enter your go.\n", UserName);

            printf("Enter a letter: ");
            scanf_s("%i", &x);

            printf("Enter a Number: ");
            scanf_s("%i", &y);

            printf("%i", x);
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

int validGo(int x, int y) {

    //If the go is out of bounds
        if (x>3 || y>3) {
           
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
        if (x>0 && y>0 && x<3 && y<3 ) {


            return 0;
        }
} 

int computersGo(int *px, int *py) {
    int range;
    range = (2-0) + 1;
    srand(time(NULL));
    printf("%i", rand() % range + 0);
}
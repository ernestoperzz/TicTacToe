#include <stdio.h>

char board[3][3] = { {'O', ' ', ' '}, {'X', 'O', ' '}, {'X', ' ', 'O'} };

void printboard();

int main() {
    printboard();
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

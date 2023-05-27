#include "display.h"
#ifndef BOARD_SIZE
#define BOARD_SIZE 11
#endif





void display_prices(wchar_t piece){
  if (piece == Tour_noir || piece == Tour_banc)
    printf(" %lc coute %d points\n", piece, 5);
  else if(piece == Reine_banc || piece == Reine_noir)
    printf(" %lc coute %d points\n", piece, 10);
  else
    printf(" %lc coute %d points\n", piece, 3);
}
// Fonction d'affichage du plateau
void displayBoard(ChessPiece board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("********displayBoard**********\n");
    printf("   A  B  C  D  E  F  G  H  I  J  K\n");
    printf("  --------------------------------\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d|", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
              if ((i + j) % 2 == 0) {
                printf("\033[0;48;5;130m");
              } 
              else {
                printf("\033[0;48;5;232m");
              }
            ChessPiece piece = board[i][j];
            printf(" %lc ", piece.symbol);
        }
        printf("\n");
    }

    printf("  --------------------------------\n");
}

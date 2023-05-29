#ifndef __Include_this__
#define __Include_this__

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include <wchar.h>

#define BOARD_SIZE 11
#define Blanc 6
#define Noir 1
#define Pion_banc L'♙'
#define Pion_noir L'♟'
#define Tour_noir L'♜'
#define Cheval_noir L'♞'
#define Foux_noir L'♝'
#define Reine_noir L'♛'
#define Roi_noir L'♚'
#define Tour_banc L'♖'
#define Cheval_banc L'♘'
#define Foux_banc L'♗'
#define Reine_banc L'♕'
#define Roi_banc L'♔'

// Structure représentant une case du plateau
typedef struct {
    int row;
    int col;
} Square;

// Structure représentant une pièce d'échecs
typedef struct {
    wchar_t symbol;
    Square position;
    int color; // Nouvelle variable pour la couleur de la pièce, 6 blanc else noir
} ChessPiece;

#endif
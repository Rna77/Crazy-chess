
#include "chess_piece_rules.h"
// Vérifie si une position est valide sur l'échiquier

int New_solde(int Old_sold, int selection){
  int new_sold;
  if (selection == 0 || selection == 4)
    new_sold = Old_sold - 5;
  else if(selection == 3 || selection == 7)
    new_sold = Old_sold - 10;
  else
    new_sold = Old_sold - 3;

  return new_sold;
}

bool isValidPosition(Square position) {
    return position.row >= 0 && position.row < BOARD_SIZE && position.col >= 0 && position.col < BOARD_SIZE;
}

// Vérifie si un déplacement est valide pour un pion
bool isValidPawnMove(Square from, Square to, ChessPiece board[BOARD_SIZE][BOARD_SIZE]) {
    ChessPiece piece = board[from.row][from.col];
    int direction = (piece.color == 6) ? 1 : -1; // Direction du mouvement (vers le haut pour les blancs, vers le bas pour les noirs)

    // Vérifie si la case de destination est vide
    if (board[to.row][to.col].symbol == ' ') {
        // Vérifie le déplacement vertical
        if (from.col == to.col && from.row + direction == to.row) {
            return true;
        }
    }

    return false;
}

// Déplace une pièce sur l'échiquier
void movePiece(ChessPiece board[BOARD_SIZE][BOARD_SIZE], Square from, Square to) {
    ChessPiece piece = board[from.row][from.col];

   //Vérifie si la position de départ et la position d'arrivée  sont valides
    if (!isValidPosition(from) || !isValidPosition(to)) {
        printf("Position invalide. Veuillez réessayer.\n");
        return;
    }

    // Vérifie si la case de départ contient une pièce
    if (piece.symbol == ' ') {
        printf("Il n'y a pas de pièce à cette position. Veuillez réessayer.\n");
        return;
    }

    // Vérifie si la case d'arrivée est occupée par une pièce de la même couleur
    ChessPiece targetPiece = board[to.row][to.col];
    if (targetPiece.symbol != ' ' && piece.color == targetPiece.color) {
        printf("Une pièce de la même couleur occupe la case d'arrivée. Veuillez réessayer.\n");
        return;
    }

    // Vérifie si le déplacement est valide pour un pion
    if ((piece.symbol == Pion_banc || piece.symbol == Pion_noir) && !isValidPawnMove(from, to, board)) {
        printf("Déplacement invalide pour un pion. Veuillez réessayer.\n");
        return;
    }

    // Effectue le déplacement
    board[from.row][from.col].symbol = ' ';
    board[to.row][to.col].symbol = piece.symbol;
    board[to.row][to.col].color = piece.color;
    board[to.row][to.col].position = to;

    printf("Déplacement effectué avec succès.\n");
}

// Convertit une chaîne de caractères représentant une position en structure Square
Square parsePosition(char* input) {
    Square position;

    if (input[0] >= 'A' && input[0] <= 'K') {
        position.col = input[0] - 'A';
    } else if (input[0] >= 'a' && input[0] <= 'k') {
        position.col = input[0] - 'a';
    } else {
        position.col = -1;
    }

    if (input[1] >= '1' && input[1] <= '9') {
        position.row = input[1] - '1';  
    } 
    else {
        position.row = -1;
    }
  if(input[2] =='0')
    position.row = 9;
  if (input[2]=='1')
    position.row = 10;


    return position;
}
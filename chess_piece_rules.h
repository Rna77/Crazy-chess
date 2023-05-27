#include "chess_types.h"

int New_solde(int Old_solde, int selection);


bool isValidPosition(Square position);

bool isValidPawnMove(Square from, Square to, ChessPiece board[BOARD_SIZE][BOARD_SIZE]);

void movePiece(ChessPiece board[BOARD_SIZE][BOARD_SIZE], Square from, Square to);

Square parsePosition(char* input);
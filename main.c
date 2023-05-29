#include "display.h"
#include "chess_piece_rules.h"
#include "chess_types.h"


int main() {
  // POUR AFFICHER UNICODE(les pionts)
  setlocale(LC_CTYPE, "");
  int Solde_Joueur_1 = 40, Solde_Joueur_2 = 40;
  int select; 
  //wchar_t: type de pieces d'eches de caracteres unicode 
	wchar_t list_of_pieces[8] = {Tour_banc, Cheval_banc, Foux_banc, Reine_banc, Tour_noir, Cheval_noir, Foux_noir, Reine_noir};
  //cout des pieces
  int points[4] = {5, 3, 3, 10};
    // Initialisation du plateau vide
    ChessPiece board[BOARD_SIZE][BOARD_SIZE];
	printf("============== starting the chess game==============\n");
	printf("Pion Noir:  %lc\n", Pion_banc);

    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // Initialise toutes les cases avec un symbole vide et une couleur par défaut
            board[i][j].symbol = ' ';   
        }
    }

   // emplacement des pieces par defaut 
    board[0][0].symbol = Pion_banc; // Pion blanche en haut à gauche
    board[0][0].color = Blanc;
    board[1][5].symbol = Roi_banc; // Roi blanc
    board[1][5].color = Blanc;
    board[0][10].symbol = Pion_banc; // Pion blanche en haut à droite
    board[0][10].color = Blanc;
    board[1][1].symbol = Pion_banc; // Pion blanche en haut à droite
    board[1][1].color = Blanc;  
    board[2][2].symbol = Pion_banc; // Pion blanche en haut à droite
    board[2][2].color = Blanc;
    board[3][3].symbol = Pion_banc; // Pion blanche en haut à droite
     board[3][3].color = Blanc;
    board[1][9].symbol = Pion_banc; // Pion blanche en haut à droite
    board[1][9].color = Blanc;  
    board[2][8].symbol = Pion_banc; // Pion blanche en haut à droite
    board[2][8].color = Blanc;
    board[3][7].symbol = Pion_banc;// Pion blanche en haut à droite
     board[3][7].color = Blanc;
    
    board[10][0].symbol = Pion_noir; // Pion noire en bas à gauche
    board[10][0].color = Noir;
    board[9][5].symbol = Roi_noir; // Roi noir
    board[9][5].color = Noir;
    board[8][2].symbol = Pion_noir; // Pion noire en bas à droite
    board[8][2].color = Noir;
    board[7][3].symbol = Pion_noir; // Pion noire en bas à droite
    board[7][3].color = Noir;
    board[9][1].symbol = Pion_noir; // Pion noire en bas à droite
    board[9][1].color = Noir;
    board[10][10].symbol = Pion_noir;// Pion noire en bas à droite
    board[10][10].color = Noir;
    board[9][9].symbol = Pion_noir; // Pion noire en bas à droite
    board[9][9].color = Noir;
    board[8][8].symbol = Pion_noir; // Pion noire en bas à droite
    board[8][8].color = Noir;
    board[7][7].symbol = Pion_noir; // Pion noire en bas à droite
    board[7][7].color = Noir;
  
    // Affichage du plateau
   displayBoard(board);

    // Boucle principale du jeu
  
    while (Solde_Joueur_1 >= 3  ) {
      printf("========= Joueur 1 ============\n");
        char strpose[3] = {'S', 'S', 'S'};
        
      if(Solde_Joueur_1 >= 3)
      {
      for(i = 0; i < 4; i++)
        {
          printf("%d - ", i);
          display_prices(list_of_pieces[i]);
        }
      printf("Votre solde est %d Veuillez selectioner une piece à acheter, ou entrer -1 pour stop : ", Solde_Joueur_1);
      scanf("%d", &select);
      if(select == -1) break;
      while( Solde_Joueur_1 < points[select])
        {
      printf("Votre solde %d  est insuffisant pour acheter  la piece %lc, Veuillez selectioner une autre piece; \n", Solde_Joueur_1, list_of_pieces[select]);
      scanf("%d", &select);
        }
      Solde_Joueur_1 = New_solde(Solde_Joueur_1, select);
      printf("Veuillez entrer la position de la nouvel pièce que vous avez acheté (ex: A1): ");
        scanf("%3s", strpose);
        Square position = parsePosition(strpose);
        while(position.row > 3)
          {
          printf("Position des blanc invalide, veuillez entrer une position entre A1 et K4: ");
        scanf("%3s", strpose);
        position = parsePosition(strpose);
          }
        board[position.row][position.col].symbol = list_of_pieces[select];
        board[position.row][position.col].color = Blanc;
      }
      // Updat Board
       displayBoard(board);
    }


      while (Solde_Joueur_2 >= 3) {
	printf("========= Joueur 2 ============\n");
        char strpose[3] = {'S', 'S', 'S'};
        int select;
      if(Solde_Joueur_2 >= 3)
      {
      for(i = 4; i < 8; i++)
        {
          printf("%d - ", i-4);
          display_prices(list_of_pieces[i]);
        }
      printf("Votre solde est %d Veuillez selectioner une piece à acheter, ou entrer -1 pour stop : ", Solde_Joueur_2);
      scanf("%d", &select);
      if(select == -1) break;
      while(Solde_Joueur_2 < points[select])
        {
      printf("Votre solde %d  est insuffisant pour acheter  la piece %lc, Veuillez selectioner une autre piece; \n", Solde_Joueur_2, list_of_pieces[select+4]);
      scanf("%d", &select);
        }
      Solde_Joueur_2 = New_solde(Solde_Joueur_2, select);
        
      printf("Veuillez entrer la position de la nouvel pièce que vous avez acheté (ex: A1): ");
        scanf("%3s", strpose);
        Square position = parsePosition(strpose);
        while(position.row < 7)
          {
          printf("Position des Noir invalide, veuillez entrer une position entre A8 et K11: ");
        scanf("%3s", strpose);
        position = parsePosition(strpose);
          }
          
        board[position.row][position.col].symbol = list_of_pieces[select+4];
        board[position.row][position.col].color = Noir;
      }
      // Updat Board
       displayBoard(board);
    }
  
  while(true)
    {
        char fromStr[3];
        char toStr[3];

        printf("Veuillez entrer la position de la pièce que vous souhaitez déplacer (ex: A1): ");
        scanf("%3s", fromStr);
        Square from = parsePosition(fromStr);

        printf("Veuillez entrer la position où vous souhaitez déplacer la pièce (ex: B2): ");
        scanf("%3s", toStr);
        Square to = parsePosition(toStr);

        movePiece(board, from, to);

        // Affichage du plateau après le déplacement
       displayBoard(board);
    }

    return 0;
}

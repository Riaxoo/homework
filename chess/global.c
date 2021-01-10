

int board[8][8] = {
                -1,-2,-3,-4,-5,-3,-2,-1,
                -6,-6,-6,-6,-6,-6,-6,-6,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                6, 6, 6, 6, 6, 6 ,6, 6,
                1 ,2, 3, 4, 5, 3 ,2, 1
        };
int tempboard[8][8] = {
                -1,-2,-3,-4,-5,-3,-2,-1,
                -6,-6,-6,-6,-6,-6,-6,-6,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                6, 6, 6, 6, 6, 6 ,6, 6,
                1 ,2, 3, 4, 5, 3 ,2, 1
        };

int player = 1;
int inactive_moves;
int checkmate = 0;
int stalemate = 0;
int resigned = 0;
int number_of_pawns = 0;
int number_of_pawns_temp = 0;
int black_rook1_moved;
int black_rook2_moved;
int white_rook1_moved;
int white_rook2_moved;
int white_king_moved;
int black_king_moved;
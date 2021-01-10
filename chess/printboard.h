int board[8][8] = {-1,-2,-3,-4,-5,-3,-2,-1,
                -6,-6,-6,-6,-6,-6,-6,-6,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                6, 6, 6, 6, 6, 6 ,6, 6,
                1 ,2, 3, 4, 5, 3 ,2, 1};
int tempboard[8][8] = {-1,-2,-3,-4,-5,-3,-2,-1,
                -6,-6,-6,-6,-6,-6,-6,-6,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                0 ,0 ,0 ,0 ,0 ,0 ,0 ,0,
                6, 6, 6, 6, 6, 6 ,6, 6,
                1 ,2, 3, 4, 5, 3 ,2, 1};
void printBoard()
{
	
    char col_name[8] = {'a','b','c','d','e','f','g','h'};
    printf("\x1b[30m\x1b[46m   ");//
    int i;
	for (i=0; i<8;i++)
        printf(" %c ",col_name[i]);
    printf("   \x1b[0m\n");
    int row, p;
	for (row = 0,p=8;row<8;row++,p--)
    {
        printf("\x1b[30m\x1b[46m");
        printf(" %d ",p);
        printf("\x1b[0m\x1b[30m");
        int col;
		for (col = 0;col<8;col++)
        {
            if(row%2==0){
                col%2==0? printf("\x1b[47m"):printf("\x1b[100m");
            }else {
                col%2==0? printf("\x1b[100m"):printf("\x1b[47m");
            }
            switch (board[row][col])
            {
                case 0:
                    printf("   ");
                    break;
                case -1:
                    printf(" ♜ ");
                    break;
                case -2:
                    printf(" ♞ ");
                    break;
                case -3:
                    printf(" ♝ ");
                    break;
                case -4:
                    printf(" ♛ ");
                    break;
                case -5:
                    printf(" ♚ ");
                    break;
                case -6:
                    printf(" ♟ ");
                    break;
                case 1:
                    printf(" ♖ ");
                    break;
                case 2:
                    printf(" ♘ ");
                    break;
                case 3:
                    printf(" ♗ ");
                    break;
                case 4:
                    printf(" ♕ ");
                    break;
                case 5:
                    printf(" \u2654 ");
                    break;
                case 6:
                    printf(" ♙ ");
                    break;
                default:
                    break;
            }
        }
        printf("\x1b[30m\x1b[46m");
        printf(" %d ",p);
        printf("\x1b[0m\n");
    }
    printf("\x1b[30m\x1b[46m   ");
	for (i=0; i<8;i++)
        printf(" %c ",col_name[i]);
    printf("   \x1b[0m\n");
}
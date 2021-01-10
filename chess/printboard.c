
#include "global.h"


void printBoard()
{
    char col_name[8] = {'a','b','c','d','e','f','g','h'};
    printf("\x1b[30m\x1b[46m   ");//
    int i;
	for (i=0; i<8;i++)
        printf("%c ",col_name[i]);
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
                    printf("  ");
                    break;
                case -1:
					printf("\u265C ");
                    break;
                case -2:
					printf("\u265E ");
                    break;
                case -3:
					printf("\u265D ");
                    break;
                case -4:
					printf("\u265B ");
                    break;
                case -5:
					printf("\u265A ");
                    break;
                case -6:
					printf("\u265F ");
                    break;
                case 1:
					printf("\u2656 ");
                    break;
                case 2:
					printf("\u2658 ");
                    break;
                case 3:
					printf("\u2657 ");
                    break;
                case 4:
					printf("\u2655 ");
                    break;
                case 5:;
					printf("\u2654 ");
                    break;
                case 6:
					printf("\u2659 ");
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
        printf("%c ",col_name[i]);
    printf("   \x1b[0m\n");
}


#include "global.h"


void castle(int r1,int c1,int r2,int c2)
{
    if (r1 == 0)
    {
        if (c2 == 6)
        {
            board[0][7] = 0;
            board[0][5] = -1;
        }
        if (c2 == 2)
        {
            board[0][0] = 0;
            board[0][3] = -1;
        }
    }
    else
    {
        if (c2 == 6)
        {
            board[7][7] = 0;
            board[7][5] = 1;
        }
        if (c2 == 2)
        {
            board[7][0] = 0;
            board[7][3] = 1;
        }
    }
}

void pawn_promotion(int r1, int c1)
{
    char ch;
    printf("Which pawn do you want to promote?\n ");
    if (player)
    {
        printf("Enter Q for Queen\n\tH for Horse\n\tR for Rook\n\tB for Bishop\n");
        fflush(stdin);
        scanf(" %c",&ch);
        switch (ch)
        {
            case 'Q':
                board[r1][c1] = 4;
                break;
            case 'H':
                board[r1][c1] = 2;
                break;
            case 'R':
                board[r1][c1] = 1;
                break;
            case 'B':
                board[r1][c1] = 3;
                break;
            default:
                printf("Invalid input!\nPlease enter a valid input\n");
                pawn_promotion(r1,c1);
        }
    }
    else
    {
        printf("Enter q for Queen\n\th for Horse\n\tr for Rook\n\tb for Bishop\n");
        fflush(stdin);
        scanf(" %c",&ch);
        switch (ch)
        {
            case 'q':
                board[r1][c1] = -4;
                break;
            case 'h':
                board[r1][c1] = -2;
                break;
            case 'r':
                board[r1][c1] = -1;
                break;
            case 'b':
                board[r1][c1] = -3;
                break;
            default:
                printf("Invalid input!\nPlease enter a valid input\n");
                pawn_promotion(r1,c1);
        }
    }
}

int isKingSafe(int Board[][8])
{
    int r = -1,c = -1;
    int i;
	for(i = 0;i<8;i++)
    {
        int j;
		for(j = 0;j<8;j++)
        {
            if (((Board[i][j] == 5) && player) || ((Board[i][j] == -5) & !player) )
            {
                r = i;
                c = j;
                i = 8;
                break;
            }
        }
    }
    if (player)
    {
        player = 0;
        int i;
		for(i = 0;i<8;i++)
        {
            int j;
			for(j = 0;j<8;j++)
            {
                if (Board[i][j]>=0)
                    continue;
                else if (isValidMove(Board,i,j,r,c))
                {
                    player = 1;
                    return 0;
                }
            }
        }
        player = 1;
    }
    else
    {
        player = 1;
        int i;
		for(i = 0;i<8;i++)
        {
            int j;
			for(j = 0;j<8;j++)
            {
                if (Board[i][j]<=0)
                    continue;
                else if (isValidMove(Board,i,j,r,c))
                {
                    player = 0;
                    return 0;
                }
            }
        }
        player = 0;
    }
    return 1;
}


int isCastle(int Board[][8],int r1,int c1,int r2,int c2)
{
    if (!isKingSafe(Board))
        return 0;
    int res = 0;
    if (r1 == 0 && c1 == 4)
    {
        if (black_king_moved)
            return 0;
        if (c2 == 6 && !black_rook2_moved && (Board[0][7] == -1))
        {
            int i;
			for (i = c1+1;i<=6;i++)
            {
                if (Board[r1][i] == 0)
                {
                    res = 1;
                    continue;
                }
                return 0;
            }
        }
        else if (c2 == 2 && !black_rook1_moved && (Board[0][0] == -1))
        {
            int i;
			for (i = c1-1;i>=1;i--)
            {
                if (Board[r1][i] == 0)
                {
                    res = 1;
                    continue;
                }
                return 0;
            }
        }
    }
    else if (r1 == 7 && c1 == 4)
    {
        if (white_king_moved)
            return 0;
        if (c2 == 6 && !white_rook2_moved && (board[7][7] == 1))
        {
            int i;
			for (i = c1+1;i<=6;i++)
            {
                if (Board[r1][i] == 0)
                {
                    res = 1;
                    continue;
                }
                return 0;
            }
        }
        else if (c2 == 2 && !white_rook1_moved  && (board[7][0] == 1))
        {
            int i;
			for (i = c1-1;i>=1;i--)
            {
                if (Board[r1][i] == 0)
                {
                    res = 1;
                    continue;
                }
                return 0;
            }
        }
    }
    return res;
}

int isValidMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int pawn = Board[r1][c1];
    if ((player && pawn>0) || ((player == 0 )&& pawn<0))
    {
        switch (pawn)
        {
            case 6:
                if (whiteSoldierMove(Board,r1,c1,r2,c2)) return 1;
                return 0;
                break;
            case -6:
                if (blackSoldierMove(Board,r1,c1,r2,c2)) return 1;
                return 0;
                break;
            case 5:
            case -5:
                if (kingMove(Board,r1,c1,r2,c2)) return 1;
                return 0;
                break;
            case 3:
            case -3:
                if (camelMove(Board,r1,c1,r2,c2))return 1;
                return 0;
                break;
            case 2:
            case -2:
                if (horseMove(Board,r1,c1,r2,c2)) return 1;
                return 0;
                break;
            case 1:
            case -1:
                if (elephantMove(Board,r1,c1,r2,c2)) return 1;
                return 0;
                break;
            case 4:
            case -4:
                if (elephantMove(Board,r1,c1,r2,c2) || camelMove(Board,r1,c1,r2,c2))
                    return 1;
                return 0;
                break;
        }
        //return 1;
    }
    return 0;
}


void quit(void)
{
    // todo tekrar sor quit mi 
    puts("bye ...");
    exit(0);
}
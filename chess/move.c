#include "global.h"

int makeMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int temp;
    temp = Board[r2][c2];
    Board[r2][c2] = Board[r1][c1];
    Board[r1][c1] = 0;
    if (!isKingSafe(Board))
    {
        Board[r1][c1] = Board[r2][c2];
        Board[r2][c2] = temp;
        return 0;
    }
    else
    {
        player = player?0:1;
        return 1;
    }
}

int whiteSoldierMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int res;
    if (c1 == c2 )
    {
        if ((r1 == 6) && (Board[r2][c2] == 0) && (Board[r1 - 1][c2] == 0) &&  (r2==4 || r2==5))
            res = 1;
        else if ((r2+1) == r1 && (Board[r2][c2] == 0))
            res = 1;
        else
            res = 0;
    }
    else if ((Board[r2][c2]<0) && (r2 == (r1 - 1)) && (c2 == (c1 - 1) ||  c2 == (c1+1)))
        res = 1;
    else
        res = 0;
    return res;
}

int blackSoldierMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int res;
    if (c1 == c2 )
    {
        if ((r1 == 1) && (board[r2][c2] == 0) && (Board[r1 + 1][c2] == 0) &&  (r2==3 || r2==2))
            res = 1;
        else if ((r2-1) == r1 && (Board[r2][c2] == 0))
            res = 1;
        else
            res = 0;
    }
    else if ((Board[r2][c2]>0) && (r2 == (r1 + 1)) && (c2 == (c1 - 1) ||  c2 == (c1+1)))
        res = 1;
    else
        res = 0;
    return res;
}

int horseMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int res;
    if (player && Board[r2][c2]>0) return 0;
    else if (!player && Board[r2][c2]<0) return 0;
    if (((r2 == (r1+2)) || (r2 == (r1-2))) && ((c2 == (c1+1)) || (c2 == (c1-1))))
        res = 1;
    else if (((c2 == (c1+2)) || (c2 == (c1-2))) && ((r2 == (r1+1)) || (r2 == (r1-1))))
        res = 1;
    else
        res = 0;
    return res;
}

int elephantMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int res = 1;
    if (player && Board[r2][c2]>0)
        return 0;
    else if (!player && Board[r2][c2]<0)
        return 0;
    if (r1 == r2)
    {
        if (c1>c2)
        {
            int i;
			for(i = (c1-1);i>c2;i--)
            {
                if (Board[r2][i] == 0) continue;
                res = 0;
                break;
            }
        }
        else if (c2>c1)
        {
            int i;
			for(i = (c1+1);i<c2;i++)
            {
                if (Board[r2][i] == 0) continue;
                res = 0;
                break;
            }
        }
        else
            return 0;
    }
    else if(c1 == c2)
    {
        if (r1>r2)
        {
            int i;
			for(i = (r1-1);i>r2;i--)
            {
                if (Board[i][c2] == 0) continue;
                res = 0;
                break;
            }
        }
        else if (r2>r1)
        {
            int i;
			for(i = (r1+1);i<r2;i++)
            {
                if (Board[i][c2] == 0) continue;
                res = 0;
                break;
            }
        }
        else
            return 0;
    }
    else
        return 0;
    return res;
}

int camelMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int res = 1;
    if (player)
    {
        if (Board[r2][c2]>0)
            return 0;
    }
    else
        if (Board[r2][c2]<0)
            return 0;
    if (r2>r1 && c2>c1)
    {
        if ((r2 - r1) == (c2 - c1))
        {
            int i, j;
			for(i = r1+1,j = c1+1;i<r2;i++,j++)
            {
                if (Board[i][j] == 0)
                    continue;
                res = 0;
                break;
            }
        }
        else
            res = 0;
    }
    else if(r2>r1 && c2<c1)
    {
        if ((r2 - r1) == (c1 - c2))
        {
            int i, j;
			for(i = r1+1,j = c1-1;i<r2;i++,j--)
            {
                if (Board[i][j] == 0)
                    continue;
                res = 0;
                break;
            }
        }
        else
            res = 0;
    }
    else if(r1>r2 && c2>c1)
    {
        if ((r1 - r2) == (c2 - c1))
        {
            int i, j;
			for(i = r1-1,j = c1+1;j<c2;i--,j++)
            {
                if (Board[i][j] == 0)
                    continue;
                res = 0;
                break;
            }
        }
        else
            res = 0;
    }
    else if(r2<r1 && c2<c1)
    {
        if ((r1 - r2) == (c1 - c2))
        {
            int i, j;
			for(i = r1-1,j = c1-1;i>r2;i--,j--)
            {
                if (Board[i][j] == 0)
                    continue;
                res = 0;
                break;
            }
        }
        else
            res = 0;
    }
    else
        res = 0;
    return res;
}

int kingMove(int Board[][8],int r1,int c1,int r2,int c2)
{
    int res = 0;
    if (r2 == r1 && !(c2 == c1 + 1 || c2 == c1 - 1))
        if (isCastle(Board,r1,c1,r2,c2))
        {
            castle(r1,c1,r2,c2);
            return 1;
        }
    if (player)
    {
        if (Board[r2][c2]>0)
            return 0;
    }
    else
        if (Board[r2][c2]<0)
            return 0;
    if ((r2 == r1 + 1 || r2 == r1 -1) &&  (c2 == c1 + 1 || c2 == c1 -1))
        res =  1;
    else if ((r2 == r1) && (c2 == c1 + 1 || c2 == c1 - 1) )
        res = 1;
    else if ((c2 == c1) && (r2 == r1 + 1 || r2 == r1 - 1) )
        res = 1;
    else
        res = 0;
    return res;
}

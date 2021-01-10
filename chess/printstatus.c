
#include "global.h"

void printCheck(void)
{
    if (player)
    {
        printf("WHITE KING IN CHECK !!\n");
    }
    else
    {
        printf("BLACK KING IN CHECK !!\n");
    }
}

void printInvalidMove()
{
    inactive_moves--;
    printf("INVALID MOVE\n");    
}

void printVictory()
{
    if (player)
    {
        printf("WHITE WINS\n");
    }
    else
    {
        printf("BLACK WINS\n");
    }
    
}

void printCheckmate()
{
    printf("CHECKMATE !\n");    
}

void printStalemate()
{
    printf("STALEMATE\n"); 
}

void printThanks()
{
    printf("THANKS FOR PLAYING\n");  
}

void print50()
{
    printf("FIFTY INACTIVE MOVES\n");    
}

void printDraw()
{
    printf("MATCH DRAW !!\n");   
}

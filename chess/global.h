#ifndef __global_h
#define __global_h

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


void run(void);
void quit(void);

void printInvalidMove(void);
void printCheckmate(void);
void printStalemate(void);
void printThanks(void);
void print50(void);
void printDraw(void);
void printCheck(void);
void printVictory(void);

int isValidMove(int [][8],int ,int ,int ,int);
int makeMove(int [][8],int ,int ,int ,int);
int whiteSoldierMove(int [][8],int ,int ,int ,int);
int blackSoldierMove(int [][8],int ,int ,int ,int);
int horseMove(int [][8],int ,int ,int ,int);
int elephantMove(int [][8],int ,int ,int ,int );
int camelMove(int [][8],int ,int ,int ,int );
int kingMove(int [][8],int ,int ,int ,int );
int isCastle(int [][8],int ,int ,int ,int );
int isKingSafe(int [][8]);
int playerHasValidMove(void);
void castle(int ,int ,int ,int );
void pawn_promotion(int ,int );
void printBoard(void);

extern int board[8][8];
extern int tempboard[8][8];

extern int player;
extern int inactive_moves;
extern int checkmate;
extern int stalemate;
extern int resigned;
extern int number_of_pawns;
extern int number_of_pawns_temp;
extern int black_rook1_moved;
extern int black_rook2_moved;
extern int white_rook1_moved;
extern int white_rook2_moved;
extern int white_king_moved;
extern int black_king_moved;

#endif

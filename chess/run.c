
#include "global.h"


int playerHasValidMove()
{
    number_of_pawns = 0;
    int i,j;
    for (i = 0;i<8;i++)
        for(j = 0;j<8;j++)
        {
            tempboard[i][j] = board[i][j];
            if (board[i][j] != 0)
                number_of_pawns++;
        }
    int r = -1,c = -1;
    for (r = 0;r<8;r++)
    {
        for(c = 0;c<8;c++)
        {
            if ((board[r][c] == 0) || (player && board[r][c]<0) || (!player && board[r][c]>0))
                continue;
            for (i = 0;i<8;i++)
                for(j = 0;j<8;j++)
                    if(isValidMove(board,r, c, i, j))
                    {
                        tempboard[i][j] = tempboard[r][c];
                        tempboard[r][c] = 0;
                        if(isKingSafe(tempboard))
                        {
                            tempboard[i][j] = board[i][j];
                            tempboard[r][c] = board[r][c];
                            return 1;
                        }
                        tempboard[i][j] = board[i][j];
                        tempboard[r][c] = board[r][c];
                    }
        }
    }
    if (!isKingSafe(board))
        checkmate = 1;
    else
        stalemate = 1;
    player = player?0:1;
    return 0;
}

void run(void)
{
    char move[5], c;

    fflush(stdin);
    getchar();
//    printf("\n");
    FILE* file;
    file = fopen("Moves.txt","w");

    while (playerHasValidMove())
    {
        if (number_of_pawns_temp == number_of_pawns)
            inactive_moves++;
        else
            inactive_moves = 1;
        number_of_pawns_temp = number_of_pawns;
        if (inactive_moves>50)
            break;
        printBoard();
        if (!isKingSafe(board))
            printCheck();
        printf("%s's turn\nEnter your move - ",player?"White":"Black");
        scanf("%s",move);
        printf("\e[1;1H\e[2J");
        int len,start[2],end[2];
        len = (int)strlen(move);
        if (len == 1 && (move[0] == 'r' || move[0] == 'R'))
        {
            resigned = 1;
            break;
        }
        if (len == 1 && (move[0] == 's' || move[0] == 'S'))
        {
            saveGame();
            break;
        }

        if ((len == 4) && isalpha(move[0]) && isalpha(move[2]) && isdigit(move[1]) && isdigit(move[3]) )
        {
            switch(move [0])
            {
                case 'a':
                    start[1]=0;
                    break;
                case 'b':
                    start[1]=1;
                    break;
                case 'c':
                    start[1]=2;
                    break;
                case 'd':
                    start[1]=3;
                    break;
                case 'e':
                    start[1]=4;
                    break;
                case 'f':
                    start[1]=5;
                    break;
                case 'g':
                    start[1]=6;
                    break;
                case 'h':
                    start[1]=7;
                    break;
                default:
                    printInvalidMove();
                    continue;
            }
            start[0] = ('9' - move[1]) - 1;
            end[0]= ('9' - move[3]) - 1;
            if (start[0]>8 || end[0]>8)
            {
                printInvalidMove();
                continue;
            }
            switch(move [2])
            {
                case 'a':
                    end[1]=0;
                    break;
                case 'b':
                    end[1]=1;
                    break;
                case 'c':
                    end[1]=2;
                    break;
                case 'd':
                    end[1]=3;
                    break;
                case 'e':
                    end[1]=4;
                    break;
                case 'f':
                    end[1]=5;
                    break;
                case 'g':
                    end[1]=6;
                    break;
                case 'h':
                    end[1]=7;
                    break;
                default:
                    printInvalidMove();
                    continue;
            }
            if (isValidMove(board,start[0],start[1],end[0],end[1]))
            {
                if ((board[start[0]][start[1]] == 6 && start[0] == 1) || (board[start[0]][start[1]] == -6 && start[0] == 6))
                    pawn_promotion(start[0], start[1]);
                if(makeMove(board,start[0],start[1],end[0],end[1]))
                {
                    file = fopen("Moves.txt","a");
                    if (file == NULL){
                        printf("ERORR!\n");
                    }
                    else
                    {
                        fprintf(file,"%s's move - %.4s\n",!player?"White":"Black",move);
                        fclose(file);
                    }
                    switch(board[end[0]][end[1]])
                    {
                        case 5:
                        case -5:
                            if (!player)
                                white_king_moved = 1;
                            else
                                black_king_moved = 1;
                            break;
                        case 1:
                        case -1:
                            if (start[0] == 0 && start[1] == 0)
                                black_rook1_moved = 1;
                            else if (start[0] == 0 && start[1] == 7)
                                black_rook2_moved = 1;
                            else if (start[0] == 7 && start[1] == 0)
                                white_rook1_moved = 1;
                            else if (start[0] == 7 && start[1] == 7)
                                white_rook2_moved = 1;
                            break;
                        default:
                            continue;
                    }
                    continue;
                }
                else
                    printInvalidMove();
                printf("\n %s king gets into check !\n",player?"White":"Black");        }
            
            else
                printInvalidMove();
        }
        else
            printInvalidMove();
    }


    printBoard();
    file = fopen("Moves.txt","a");
    if (checkmate)
    {
        printCheckmate();
        printVictory();
        fprintf(file,"%s won by checkmate\n",player?"White":"Black");
    }
    else if (stalemate)
    {
        printStalemate();
        printDraw();
        fprintf(file,"Match drawn by stalemate\n");
        
    }
    else if (inactive_moves>50)
    {
        print50();
        printDraw();
        fprintf(file,"Match drawn by 50 move rule\n");
    }
    else if (resigned)
    {
        fprintf(file,"%s resigned\n",player?"White":"Black");
        fprintf(file,"%s won\n",!player?"White":"Black");
        player = player?0:1;
        printVictory();
        
    }
    printThanks();
    fclose(file);
}

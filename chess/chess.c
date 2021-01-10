
#include "global.h"

int getChar()
{
    int c;
    do 
    {
        c = getchar();
    }
    while (c == '\n' || c == EOF);

    return c;
}

int getCommand()
{
    int cmd = -1;
    fflush(stdin);

    for ( ; ; )
    {
        puts("1. New game");
        puts("2. Load Game");
        puts("3. Quit Game");
        
        cmd = getChar();
  
        if (cmd > '0' && cmd < '4')
            break;
        
        puts("please enter valid #");
    }

    return cmd;
}

int main()
{
    system("chcp 65001");
	// todo clrscr

    black_rook1_moved = 0;
    black_rook2_moved = 0;
    white_rook1_moved = 0;
    white_rook2_moved = 0;
    white_king_moved = 0;
    black_king_moved = 0;
    player = 1;
    number_of_pawns_temp = 32;
    char move[5], c;

    printf("Welcome to Chess\n");
    printf("Do you want to read the instructions? (y/n) ");
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        FILE *fptr;
        fptr = fopen("instructions.txt", "r");
        if (fptr == NULL)
        {
            printf("Cannot open file \n");
        }
        else
        {
            int c0;
            // todo instruction.txt de icinde oyunun yuklenebilir oldugunu da belirt.
            // load yazsın 

            c = fgetc(fptr);
            while (c != EOF)
            {
                printf ("%c", c);
                c = fgetc(fptr);
            }
            fclose(fptr);
        }
    }

    printf("\n\n");

    int cmd = getCommand();

    if (cmd == '1')
    {
        run();
    }
    else if (cmd == '2')
    {
        int res = loadGame();
        if (res != 0)
            puts("There is no file to be loaded. Please start a new game\n");
        run();
    }

    quit();
}





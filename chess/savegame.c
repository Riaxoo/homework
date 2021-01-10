
#include "global.h"

#define FILENAME "chess.data"

void saveGame(void)
{
    FILE* file;
    file = fopen(FILENAME, "w");
    fwrite(board, 1, sizeof(board), file);
    fwrite(&player, 1, sizeof(player), file);
    fclose(file);
}

int loadGame(void)
{
    FILE* file;
    file = fopen(FILENAME, "rb");
    if (NULL == file)
        return -1;
    fread(board, 1, sizeof(board), file);
    fread(&player, 1, sizeof(player), file);
    fclose(file);
    return 0;
}

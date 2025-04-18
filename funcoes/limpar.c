#include <stdlib.h>
#include "prototipos.h"

void limpar(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
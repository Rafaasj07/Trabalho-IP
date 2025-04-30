#include <stdlib.h>
#include "prototipos.h"

void limpar(void)
{
#ifdef _WIN32
    system("cls"); //Apaga no windows
#else
    system("clear");  //Apaga no linux
#endif
}
#include <stdio.h>
#include <string.h>
#include "prototipos.h"

void cifrar_cesar(char *codificada, int deslocamento)
{
    int i;
    for (i = 0; i < strlen(codificada); i++)
    {
        codificada[i] = codificada[i] + deslocamento;
    }
    codificada[i] = '\0';
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void ir_para (int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
    /*   0x1B >> ESC em ASCII, sinaliza que está começando uma sequência ANSI.
             Sequência ANSI: caracteres especiais que controlam o comportamento da tela.

         [ (colchete) >> Após o ESC, é necessário o colchete para que a sequência ANSI funcione.

         %d %d >> Valores da função. O primeiro (y) determina a linha que o cursor será colocado e o segundo (x) a coluna.

         f >> Termina a sequência ANSI, ficando: ESC[y;xf que significa "Mova o cursor para a linha y e coluna x"
    */      
}
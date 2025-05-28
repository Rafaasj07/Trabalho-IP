#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void bordas()
{
    // O x percorrerá da coluna 3 até a coluna 78, criando as bordas horizontais (BH)

    // OBS: 196 é o código ASCII do traço horizontal(─), que usamos para fazer as bordas

    for (int x = 3; x < 79; x++)
    {
        ir_para(x, 2);
        printf("%c", 196); // BH superior

        ir_para(x, 24);
        printf("%c", 196); // BH inferior
    }

    // O y percorrerá da linha 3 até a linha 23, criando as bordas verticais (BV) e os cantos superiores (CS) e inferiores (CI)

    // OBS: 218, 191, 192 e 217 são códigos ASCII para os caracteres  ┌, ┐, └ e ┘ que usamos para fazer os cantos.
    // OBS: 179 é o código ASCII para a barra vertical (|), usado para fazer as bordas verticais.

    for (int y = 3; y < 24; y++)
    {

        ir_para(2, y);
        printf("%c", 179); // BV direito

        ir_para(79, y);
        printf("%c", 179); // BV esquerdo
    }

    ir_para(2, 2);
    printf("%c", 218); // CS esquerdo

    ir_para(79, 2);
    printf("%c", 191); // CS direito

    ir_para(2, 24);
    printf("%c", 192); // CI esquerdo

    ir_para(79, 24);
    printf("%c", 217); // CI direito
}
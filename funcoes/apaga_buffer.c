#include <stdio.h>
#include "prototipos.h"
void apaga_buffer(void){
    while (getchar() != '\n');  //“O getchar() vai ler os buffers do teclado, dígitos que sobraram após o scanf,
}                               // e aí ele vai apagar tudo diferente do \n, e quando achar o \n, apaga ele também.”
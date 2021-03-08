#include <stdio.h>
#include "libcrc32.h"

int main(void){
    int table[256];
    FillTable(table);
    for (int i = 0; i < 256; i++){
        printf("%i\t", table[i]);
    }
    return 0;
}
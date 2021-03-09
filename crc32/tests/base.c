#include <stdio.h>
#include "../libcrc32.h"

int main(void){
    unsigned int table[256];
    unsigned int expected_table[256] == {
        #include "expected_table.txt"
    };
    int fail = 0;
    FillTable(table);
    for (int i = 0; i < 256; i++){
        if (table[i] == expected_table[i]){
            fail = 1;
        }
    }
    return fail;
}
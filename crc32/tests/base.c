#include <stdio.h>
#include <string.h>
#include "../libcrc32.h"

void testFillTable(){
    unsigned int table[256];
    unsigned int expected_table[256] = {
        #include "expected_table.txt"
    };

    int fail = 0;
    FillTable(table);
    for (int i = 0; i < 256; i++){
        if (table[i] != expected_table[i]){
            fail = 1;
        }
    }

    if (fail){
        printf("Failed table\n");
    } else{
        printf("Table init successful\n");
    }
}

void tetsCRC32(){
    unsigned int expected_table[256] = {
        #include "expected_table.txt"
    };
	char *str = "The quick brown fox jumps over the lazy dog";
    unsigned int str_hash_expected = 1095738169;
    unsigned int str_hash = CRC32Update(str, strlen(str), expected_table);

    if (str_hash_expected != str_hash){
        printf("Failed table\n");
    } else{
        printf("Hashing successful\n");
    }
}

int main(void){
    testFillTable();
    tetsCRC32();
    return 0;
}
void FillTable(unsigned int* table){
    int i, j;
    unsigned int rem;
    for (i = 0; i < 256; i++) {
        rem = i;
        for (j = 0; j < 8; j++) {
            if (rem & 1) {
                rem = rem >> 1;
                rem = rem ^ 0xedb88320;
            } else{
                rem = rem >> 1;
            }
        }
        table[i] = rem;
    }
}

unsigned int CRC32Update(char* buffer, unsigned int size, unsigned int* table){
    char* p;
    char c;
    unsigned int crc = ~0;
    for (p = buffer; p < buffer+size; p++){
        c = *p;
        crc = (crc >> 8) ^ table[(crc & 0xff) ^ c];
    }
    return crc;
}

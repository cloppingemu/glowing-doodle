#include <stdio.h>
#include <string.h>
 
unsigned int rc_crc32(unsigned int crc, const char *buf, size_t len)
{
	static unsigned int table[256];
	static int have_table = 0;
	unsigned int rem;
	unsigned char octet;
	int i, j;
	const char *p, *q;
 
	/* This check is not thread safe; there is no mutex. */
	if (have_table == 0) {
		/* Calculate CRC table. */
		for (i = 0; i < 256; i++) {
			rem = i;  /* remainder from polynomial division */
			for (j = 0; j < 8; j++) {
				if (rem & 1) {
					rem >>= 1;
					rem ^= 0xedb88320;
				} else
					rem >>= 1;
			}
			table[i] = rem;
		}
		have_table = 1;
	}

    for (i=0; i<256; i++){
        printf("%u\n", table[i]);
    }
 
	crc = ~crc;
	q = buf + len;
	for (p = buf; p < q; p++) {
		octet = *p;  /* Cast to unsigned octet. */
		crc = (crc >> 8) ^ table[(crc & 0xff) ^ octet];
	}
	return ~crc;
}
 
int main() {
	const char *s = "The quick brown fox jumps over the lazy dog";
	printf("%X\n", rc_crc32(0, s, strlen(s)));
 
	return 0;
}
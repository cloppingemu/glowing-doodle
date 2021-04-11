#ifndef libcrc32_h__
#define libcrc32_h__

extern void FillTable(unsigned int* table);
extern unsigned int CRC32Update(char* buffer, unsigned int size, unsigned int* table);

#endif  // foo_h_

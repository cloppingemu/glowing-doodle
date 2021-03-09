#ifndef foo_h__
#define foo_h__

extern void FillTable(unsigned int* table);
extern unsigned int CRC32Update(char* buffer, unsigned int size, unsigned int* table);

#endif  // foo_h_

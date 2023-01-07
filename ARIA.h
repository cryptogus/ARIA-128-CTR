#ifndef _ARIA_
#define _ARIA_

#include <stdio.h>
#include <stdlib.h>

void ARIA_en(unsigned char plaintext[], unsigned char key[], unsigned char ciphertext[]);
void keyexpend(unsigned char* key, unsigned char(*ek)[16]);
void rotation(unsigned char* W, unsigned char N, unsigned char m, unsigned char* X);
void F0(unsigned char* in, unsigned char* C, unsigned char* output);
void Fe(unsigned char* in, unsigned char* C, unsigned char* output);
void Ff(unsigned char* in, unsigned char* C1, unsigned char* C2, unsigned char* output);

#endif // !_ARIA_

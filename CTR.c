#include "ARIA.h"

unsigned char* CTR(unsigned char* text, size_t Byte) {
	
	/* key 박아두기*/
	unsigned char key_ctr[16] = { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c };
	unsigned char IV_ctr[16] = { 0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff };
	
	unsigned char cipher[16] = { 0, };
	unsigned char plain[16] = { 0, };
	unsigned int sum = 0;
	
	unsigned char* output = (unsigned char*)calloc(Byte + 1, sizeof(unsigned char));
	
	for (int i = 0; i < (Byte / 16) + 1; i++) {

		ARIA_en(IV_ctr, key_ctr, IV_ctr);

		for (int j = 0; j < 16; j++) {
			if (Byte == j + i * 16) {
				break;
			}
			plain[j] = text[j + 16 * i];
			cipher[j] = plain[j] ^ IV_ctr[j];
			output[j + 16 * i] = cipher[j];

		};

		sum = 0;
		for (int k = 0; k < 16; k++) { // CTR정수로 변형 -- sum변수에 저장
			sum |= IV_ctr[k];
			sum <<= 8;
		}
		sum += 1;// ---- CTR + 1
		sum &= 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111;
		//sum %= (1 << 128);
		for (int k = 15; k >= 0; k--) { // CTR값을 비트로 바꿈
			IV_ctr[k] = sum & 0xff;
			sum = sum >> 8;
		}
	}
	output[Byte] = '\0';
	return output;
}

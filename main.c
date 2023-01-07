#include "CTR.h"
#include <string.h>


//padding은 구현하지 않음

int main(int argc, unsigned char* argv[])
{
	
	unsigned char* dst = NULL;

	if (argc == 2) {
		dst = CTR(argv[1], strlen(argv[1]));
		printf("output: %s\n", dst);
	}
	else {
		fprintf(stderr, "Usage: %s <text>\n", argv[0]);
		return -1;
	}
	
	return 0;

	/** Test
	*unsigned char* text = "kookmin university";
	*unsigned char* text2 = NULL;
	*unsigned char* text3 = NULL;
	* 
	*printf("%zu\n", strlen(text)); //size_t 는 시스템에 따라 달라질 수 있는 자료형, 따라서 %zu를 사용하여 코딩을 해놓으면 따로 바꾸어줄 필요가 없으므로 이식성이 높아짐
	*printf("%s\n", text);
	*text2 = CTR(text, strlen(text));
	*
	*printf("%s\n", text2);// -> 인코딩 문제
	*printf("%zu\n", strlen(text2));
	*
	*text3 = CTR(text2, strlen(text));
	*printf("%s\n\n", text3);
	*/
}
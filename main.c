#include "CTR.h"
#include <string.h>

// We’ve detected the file encoding as EUC-KR. When you commit changes we will transcode it to UTF-8. -> encoding problem
////ctr mode는 padding이 필요없다.(The ctr mode does not require padding.)

int main(int argc, unsigned char* argv[])
{
	
	unsigned char* dst = NULL;
	unsigned char* input = NULL;
	if (argc > 1) {
		printf("input\n");
		gets(input);
		dst = CTR(input, strlen(input));
		fprintf(stdout, "output: %s\n", dst);
		free(dst);
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

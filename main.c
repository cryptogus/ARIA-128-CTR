#include "CTR.h"
#include <string.h>

// We’ve detected the file encoding as EUC-KR. When you commit changes we will transcode it to UTF-8. -> encoding problem
////ctr mode는 padding이 필요없다.(The ctr mode does not require padding.)

int main(int argc, unsigned char* argv[])
{
	
	unsigned char* dst = NULL;
	unsigned char input[128];
	
	if (argc == 2) {
		printf("input: ");
		if (fgets(input, 128, stdin) == NULL || input[0] == '\n') { //fgets는 엔터치면 '\n' 도 포함한다 즉 배열 마지막은 \n, \0 순서이다. 따라서 strlen크기 - 1이 문자열 길이다.
			
			fprintf(stderr, "Please enter text within 128 bytes.\n");
			return 1;
		}
		//printf("%zu\n", strlen(input) -1);
		dst = CTR(input, strlen(input) - 1);
		fprintf(stdout, "output: %s\n", dst);
		free(dst); //-> 윈도우에서는 힙 메모리 할당 오류가 생긴다 원인 모르겠
	}
	else {
		fprintf(stderr, "Usage: %s start\n", argv[0]);
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

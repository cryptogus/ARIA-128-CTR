#include "CTR.h"
#include <string.h>


//padding�� �������� ����

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
	*printf("%zu\n", strlen(text)); //size_t �� �ý��ۿ� ���� �޶��� �� �ִ� �ڷ���, ���� %zu�� ����Ͽ� �ڵ��� �س����� ���� �ٲپ��� �ʿ䰡 �����Ƿ� �̽ļ��� ������
	*printf("%s\n", text);
	*text2 = CTR(text, strlen(text));
	*
	*printf("%s\n", text2);// -> ���ڵ� ����
	*printf("%zu\n", strlen(text2));
	*
	*text3 = CTR(text2, strlen(text));
	*printf("%s\n\n", text3);
	*/
}

#include <stdio.h>

struct bs{

    char d;
    int a:4;
    int  :4;    /* 空域 */
    int b:4;    /* 从下一单元开始存放 */
    int c:4;
    int e;
};

typedef struct bit_filed
{
	unsigned char a:1;
	unsigned char b:3;
	unsigned char c:4;
}BF;
 
int main()
{
	BF bit = {1,6,12};
    printf("size of bit is %d\n",sizeof(bit));//1
    printf("%d", sizeof(bs));
    return 0;
}
/*连接两个字符串的函数*/
#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void stringcat(char* s1, char* s2);
int main()
{
	char str1[100] = { '\0' };
	char str2[100] = { '\0' };
	gets(str1);
	gets(str2);
	stringcat(str1, str2);
	printf("合并后的字符串为：");
	puts(str1);
	return 0;
}
void stringcat(char* s1, char* s2)
{
	while (*s1) s1++;
	while (*s2)
	{
		*s1 = *s2;
		s1++, s2++;
	}
	*s1 = '\0';
}
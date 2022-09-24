#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char *stack, char  c);
char pop(char *stack);
int main() {
	char a[1000] = "";
	int len = 0;
	int cnt = 0;
	char stack[1000] = { '\0' };
	int k = 0;
	int i = 0;
	char ch = '\0';
	scanf("%s", a);
	len = strlen(a);
	if (len % 2 == 0)//짝수개 일 때
	{
		for ( i = 0; i < len / 2; i++)
		{
			push(stack,a[i]);
		}
	
		for (k=(len/2);k<len;k++)
		{
			ch = pop(stack);
			if (a[k]== ch)
			{
				cnt++;
			}
		}
		if (cnt == len / 2)
		{
			printf("입력한 단어 %s는 Palindrome입니다",a);
		}
		else {
			printf("입력한 단어 %s는 Palindrome이 아닙니다",a);
		}


	}
	else
	{
		for ( i = 0; i < (len / 2)+1; i++)
		{
			push(stack, a[i]);
		}
		ch=pop(stack);
		for ( i = len / 2+1; i < len; i++)
		{
			if (a[i ] == pop(stack))
			{
				cnt++;
			}
		}
		if (cnt == len / 2)
		{
			printf("입력한 단어 %s는 Palindrome입니다",a);
		}
		else {
			printf("입력한 단어 %s는 Palindrome이 아닙니다",a);
		}


	}//홀수 개일 때

	

	return 0;
}
void push(char *stack, char c)
{

	int i = 0;
	int cnt = 0;
	while (stack[i] != '\0')
	{
		cnt++;
		i++;
	}

	stack[cnt] = c;

}
char pop(char *stack)
{
	int cnt = 0;
	char *p;
	p = stack;
	char temp = '\0';
	while (*p != '\0')
	{
		cnt++;
		p++;
	}
	temp = stack[cnt - 1];
	stack[cnt - 1] = '\0';
	return temp;
}
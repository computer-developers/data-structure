#include<stdio.h>
#include<conio.h>
#include<string.h>
int top=-1,ii=0;
char i[50],p[50],s[50];
int r(char);
int f(char);
int g(char);
char pop();
void push(char);
char nextchar();
void dp(int);
int main()
{
int rank=0; 
char next,temp;
gets(i);
strncat(i,")",1);
next=nextchar();
push('(');
p[0]='\0';
while (next != '\0')
	{
		while(f(next)<g(s[top]))
		{
			temp=pop();
			strncat(p,&temp,1);
			rank=rank+r(temp);
			if (rank<1)
			{
				printf("error!!");
				getch();
				return 0;
			}
		}
		if (f(next)!=g(s[top]))
				push(next);
		else
				top--;//pop()
		next=nextchar();
	}
dp(rank);
return 0;
}
void push(char a)
{
	top++;
	s[top]=a;
}
char nextchar()
{
	ii++;
	return i[ii-1];
}
int r(char a)
{
	if((a>=97 && a<=122)||(a>=65 && a<=90))
		return 1;
	else 
		return -1;
}
int f(char a)
{
	if(a=='+'||a=='-')return 1;
	if(a=='*'||a=='/')return 3;
	if(a=='^')return 6;
	if((a>='a' && a<='z')||(a>='A' && a<='Z'))return 7;
	if(a=='(')return 9;
	if(a==')')return 0;
}
int g(char a)
{
	if(a=='+'||a=='-')return 2;
	if(a=='*'||a=='/')return 4;
	if(a=='^')return 5;
	if((a>=97 && a<=122)||(a>=65 && a<=90))return 8;
	if(a=='(')return 0;
}
char pop()
{
	top--;
	return s[top+1];
}
void dp(int rank)
{
	int b;
	if(rank!=1||top!=-1)
	{
		printf("invalid");
		return;
	}
for(b=0;p[b]!='\0';b++)
	printf("%c",p[b]);	
}

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int top=-1,ii=0,ie,ip;
char i[50],p[50],s[50];
int r(char);
int f(char);
int g(char);
char pop();
int post();
void cal();
void up(int);
void push(char);
char nextchar();
void dp();
struct neel
{
	char c;
	float a;
}e[50];
int main()
{
if(post());
{
	store();
	cal();
	dp();
	return 0;
}
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
	if((a>='a' && a<='z')||(a>='A' && a<='Z'))return 7;
	if(a=='(')return 9;
	if(a==')')return 0;
	else return 6;
}
int g(char a)
{
	if(a=='+'||a=='-')return 2;
	if(a=='*'||a=='/')return 4;
	if((a>=97 && a<=122)||(a>=65 && a<=90))return 8;
	if(a=='(')return 0;
	else return 5;
}
char pop()
{
	top--;
	return s[top+1];
}
void dp()
{
	if(ie==0)
		printf("ans=%f",e[0].a);	
	else 
		printf("error!!");	
}
int post()
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
if(rank!=1||top!=-1)
	{
		printf("invalid");
		return 0;
	}
return 1;
}
void store()
{
	ie=0;
	printf("\n");
	for(ie=0;p[ie]!='\0';ie++)
	{
		if((p[ie]>='a'&&p[ie]<='z')||(p[ie]>='A'&&p[ie]<='Z'))
		{
			printf("enter value for %c=",p[ie]);
			scanf("%f",&e[ie].a);
		}
		e[ie].c=p[ie];	
	}
	ie--;
}
void cal()
{
int b,a;
	for(;ie!=0;)
	{a=1;
		for(b=0;a==1;b++)
		{
			if(!((e[b].c>=97&&e[b].c<=122)||(e[b].c>=65&&e[b].c<=90)))
			{
				up(b);
				a--;
			}
		}
	}
}
void up(int a)
{
	int h;
	char d;
	float b,c;
	d=e[a].c;
	c=e[a-1].a;
	b=e[a-2].a;
	if(d=='+')
		e[a-2].a=b+c;
	else if(d=='-')
		e[a-2].a=b-c;
	else if(d=='*')
		e[a-2].a=b*c;
	else if(d=='/')
		e[a-2].a=b/c;
	else
		e[a-2].a=pow(b,c);
		e[a-2].c='s';
	for(h=a-1;h<=ie-2;h++)
	{
		e[h].c=e[h+2].c;
		e[h].a=e[h+2].a;
	}
	ie=ie-2;	
}

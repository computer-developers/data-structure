#include<conio.h>
#include<stdio.h>
#define size 7
void bubble(int *,int,int);
void main()
{
	int a[size],i=size,f;
	char g;
	printf("enter %d elements..",i);
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	printf("\nA-ascending\nD-descending\n");
get:g=getch();
	if(g=='a'||g=='A')
		f=1;
	else if(g=='d'||g=='D')
		f=-1;
	else
		goto get;
	bubble(&a,size,f);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void bubble(int *p,int x,int f)
{
	int i,j,t,c,x1=x;
	for(j=0;j<=x;j++)
		{
			c=0;
			for(i=0;i<x1-1;i++)
			{
				if((*(p+i))*f>(*(p+i+1))*f)
				{
					t=*(p+i+1);
					*(p+i+1)=*(p+i);
					*(p+i)=t;
					c++;
				}
			}
			x1--;
			if(!c)return;
		}
	printf("\nerror!!!");
}

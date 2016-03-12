#include<stdio.h>
#include<conio.h>
#define size 7
void insertion(int *,int,int);
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
	insertion(&a,size,f);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void insertion(int *p,int x,int f)
{
	int i,j,t;
	for(i=0;i<x-1;i++)
	{
		for(j=i+1;j>0&&(*(p+j))*f<(*(p+j-1))*f;j--)
		{
			t=*(p+j-1);
			*(p+j-1)=*(p+j);
			*(p+j)=t;
		}
	}
}

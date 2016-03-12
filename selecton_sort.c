#include<conio.h>
#include<stdio.h>
#define size 7
void selection(int *,int,int);
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
	selection(&a,size,f);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void selection(int *p,int x,int f)
{
	int i,j,k,t;
	for(i=0;i<x-1;i++)
		{
			k=i+1;
			for(j=i+2;j<x;j++)
				if((*(p+k))*f>(*(p+j))*f)
					k=j;	
			if((*(p+i))*f>(*(p+k))*f)
				{
					t=*(p+k);
					*(p+k)=*(p+i);
					*(p+i)=t;
				}
		}
}

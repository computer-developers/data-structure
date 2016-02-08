#include<stdio.h>
#include<conio.h>
#define size 7
void insertion(int *,int);
void main()
{
	int a[size],i=size;
	printf("enter %d elements..",i);
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	insertion(&a,size);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void insertion(int *p,int x)
{
	int i,j,t;
	for(i=0;i<x-1;i++)
	{
		for(j=i+1;j>0&&*(p+j)<*(p+j-1);j--)
		{
			t=*(p+j-1);
			*(p+j-1)=*(p+j);
			*(p+j)=t;
		}
	}
}

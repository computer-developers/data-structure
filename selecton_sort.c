#include<conio.h>
#include<stdio.h>
#define size 7
void selection(int *,int);
void main()
{
	int a[size],i=size;
	printf("enter %d elements..",i);
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	selection(&a,size);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void selection(int *p,int x)
{
	int i,j,k,t;
	for(i=0;i<x-1;i++)
		{
			k=i+1;
			for(j=i+2;j<x;j++)
				if(*(p+k)>*(p+j))
					k=j;	
			if(*(p+i)>*(p+k))
				{
					t=*(p+k);
					*(p+k)=*(p+i);
					*(p+i)=t;
				}
		}
}

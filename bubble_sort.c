#include<conio.h>
#include<stdio.h>
#define size 7
void bubble(int *,int);
void main()
{
	int a[size],i=size;
	printf("enter %d elements..",i);
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	bubble(&a,size);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void bubble(int *p,int x)
{
	int i,j,t,c;
	for(j=0;j<=x;j++)
		{
			c=0;
			for(i=0;i<x-1;i++)
			{
				if(*(p+i)>*(p+i+1))
				{
					t=*(p+i+1);
					*(p+i+1)=*(p+i);
					*(p+i)=t;
					c++;
				}
			}
			if(!c)return;
		}
	printf("\nerror!!!");
}

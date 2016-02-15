#include<conio.h>
#include<stdio.h>
#define size 7
void sort(int *p,int x);
int search(int *,int,int);
void main()
{
	int a[size],i;
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	sort(&a[0],size);
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("enter element...");
	scanf("%d",&i);
	if(i=search(&a[0],size,i))
	printf("place of element is %d",i);
	getch();
}
void sort(int *p,int x)
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
int search(int *a,int l,int s)
{
	int f=0,m=3;
	for(;1;)
	{
		if(*(a+m)<s)
		{
			f=m+1;
			m=(f+l)/2;
		}
		else if(*(a+m)>s)
		{
			l=m-1;
			m=(f+1)/2;
		}
		else if(*(a+m)==s)
			return m+1;
		if(f>l)
		{
			printf("element not found....");
			return 0;
		}
	}
}

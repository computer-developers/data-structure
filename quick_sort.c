#include<conio.h>
#include<stdio.h>
#define size 7
void quick(int *,int,int);
void swap(int *,int *);
void main()
{
	int i,a[size];;
	printf("enter elements..");
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	quick(&a[0],0,size-1);
	printf("\nsorted list:");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	getch();
}
void quick(int *a,int l,int u)
{
	int f=1,i,j,p,k;
	p=l;
	i=l+1;
	j=u;
	if(l>=u)
		return;
	for(;f;)
	{
		for(;*(a+i)<*(a+p);i++);
		for(;*(a+j)>*(a+p);j--);
		if(i<j)
			swap(a+i,a+j);
		else f=0;
	}
	swap(a+l,a+j);
	quick(a,l,j-1);
	quick(a,j+1,u);
}
void swap(int *i,int *j)
{
	int t;
	t=*i;
	*i=*j;
	*j=t;
}

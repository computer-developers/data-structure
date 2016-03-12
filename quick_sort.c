#include<conio.h>
#include<stdio.h>
#define size 7
void quick(int *,int,int,int);
void swap(int *,int *);
void main()
{
	int i,a[size],f;
	char g;
	printf("enter elements..");
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
	quick(&a[0],0,size-1,f);
	printf("\nsorted list:");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void quick(int *a,int l,int u,int f)
{
	int f1=1,i,j,p,k;
	p=l;
	i=l+1;
	j=u;
	if(l>=u)
		return;
	for(;f1;)
	{
		for(;(*(a+i))*f<(*(a+p))*f;i++);
		for(;(*(a+j))*f>(*(a+p))*f;j--);
		if(i<j)
			swap(a+i,a+j);
		else f1=0;
	}
	swap(a+l,a+j);
	quick(a,l,j-1,f);
	quick(a,j+1,u,f);
}
void swap(int *i,int *j)
{
	int t;
	t=*i;
	*i=*j;
	*j=t;
}

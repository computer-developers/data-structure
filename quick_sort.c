#include<conio.h>
#include<stdio.h>
int a[7];
void quick(int,int);
void swap(int *,int *);
void main()
{
	int i;
	printf("enter elements..");
	for(i=0;i<7;i++)
		scanf("%d",&a[i]);
	quick(0,6);
	printf("\nsorted list:");
	for(i=0;i<7;i++)
		printf("%d ",a[i]);
getch();
}
void quick(int l,int u)
{
	int f=1,i,j,p,k;
	p=l;
	i=l+1;
	j=u;
	if(l>=u)
		return;
	for(;f;)
	{
		for(;a[i]<a[p];i++);
		for(;a[j]>a[p];j--);
		if(i<j)
			swap(&a[i],&a[j]);
		else f=0;
	}
	swap(&a[l],&a[j]);
	quick(l,j-1);
	quick(j+1,u);
}
void swap(int *i,int *j)
{
	int t;
	t=*i;
	*i=*j;
	*j=t;
}

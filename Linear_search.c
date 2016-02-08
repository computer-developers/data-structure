#include<stdio.h>
#include<conio.h>
#define size 7
int linear(int [],int);
void main()
{
	int a[size],i=size,x;
	printf("enter %d elements..",i);
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	printf("\nenter element which would be searched...");
		scanf("%d",&x);
	if(i=linear(a,x))
		printf("\n%d element is on %d position..",x,i);
	else
		printf("\n%d element not found!!!",x);
}
int linear(int p[],int x)
{
	int i;
	for(i=0;i<size;i++)
		if(p[i]==x)
			return i+1;
	return 0;
}

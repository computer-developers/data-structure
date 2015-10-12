#include<conio.h>
#include<stdio.h>
int a[7];
void sort();
int search(int);
void main()
{
	int i;
	for(i=0;i<7;i++)
		scanf("%d",&a[i]);
	sort();
	for(i=0;i<7;i++)
		printf("%d ",a[i]);
	printf("enter element...");
	scanf("%d",&i);
	if(search(i))
	printf("place of element is %d",search(i));
getch();
}
void sort()
{
	int i,j;
	for(i=0;i<6;i++)
		for(j=i;j<7;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
}
int search(int s)
{
	int f=0,l=6,m=3;
	for(;1;)
	{
		if(a[m]<s)
		{
			f=m+1;
			m=(f+l)/2;
		}
		else if(a[m]>s)
		{
			l=m-1;
			m=(f+1)/2;
		}
		else if(a[m]==s)
			return m+1;
		if(f>l)
		{
			printf("element not found....");
			return 0;
		}
	}
}

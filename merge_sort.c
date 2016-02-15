#include<conio.h>
#include<stdio.h>
#define size 8
void merge(int *,int);
void merges(int *,int);
void main()
{
	int i,s[size];
	printf("enter elements...");
	for(i=0;i<size;i++)
		scanf("%d",&s[i]);
	merge(&s[0],size);
	for(i=0;i<size;i++)
		printf("%d ",s[i]);
	getch();
}
void merge(int *a,int i)
{
	if(i==1)
		return;
	merge(a,i/2);
	merge(a+i/2,(i+1)/2);
	merges(a,i);
}
void merges(int *a,int i)
{
	int b[i/2],c[(i+1)/2],bi=i/2,ci=(i+1)/2,k,p=0,r=0;
	for(k=0;k<bi;k++)
		b[k]=*(a+k);
	for(k=0;k<ci;k++)
		c[k]=*(a+k+bi);
	for(k=0;k<i&&p<bi&&r<ci;k++)
	{
		if(b[p]<c[r])
		{
			*(a+k)=b[p];
			p++;
		}
		else
		{
			*(a+k)=c[r];
			r++;
		}
	}
	for(;k<i&&p<bi;k++,p++)
		*(a+k)=b[p];
	for(;k<i&&r<ci;k++,r++)
		*(a+k)=c[r];
}

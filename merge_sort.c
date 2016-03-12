#include<conio.h>
#include<stdio.h>
#define size 8
void merge(int *,int,int);
void merges(int *,int,int);
void main()
{
	int i,s[size],f;
	char g;
	printf("enter elements...");
	for(i=0;i<size;i++)
		scanf("%d",&s[i]);
	printf("\nA-ascending\nD-descending\n");
get:g=getch();
	if(g=='a'||g=='A')
		f=1;
	else if(g=='d'||g=='D')
		f=-1;
	else
		goto get;
	merge(&s[0],size,f);
	printf("\nsorted elements...");
	for(i=0;i<size;i++)
		printf("%d ",s[i]);
}
void merge(int *a,int i,int f)
{
	if(i==1)
		return;
	merge(a,i/2,f);
	merge(a+i/2,(i+1)/2,f);
	merges(a,i,f);
}
void merges(int *a,int i,int f)
{
	int b[i/2],c[(i+1)/2],bi=i/2,ci=(i+1)/2,k,p=0,r=0;
	for(k=0;k<bi;k++)
		b[k]=*(a+k);
	for(k=0;k<ci;k++)
		c[k]=*(a+k+bi);
	for(k=0;k<i&&p<bi&&r<ci;k++)
	{
		if(b[p]*f<c[r]*f)
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

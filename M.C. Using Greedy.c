#include<stdio.h>
#include<conio.h>
struct tab
{
	int v,n;
}*c;
int nc;
void method(int);
int add(int,int);
void scan();
void main()
{
 	int am;
 	scan();
 	printf("\nEnter amount you want:");
 	scanf("%d",&am);
 	method(am);
	getch();
}
void scan()
{
	int i,a,b;
	printf("how many different types of coin you have??");
	scanf("%d",&nc);
	c=(struct tab *)calloc(nc,sizeof(struct tab));
	for(i=0;i<nc;i++)
	{
		printf("enter value & number of coin..");
		scanf("%d %d",&c[i].v,&c[i].n);
	}
}
void method(int am)
{
	int s=0,x,ind=0,i,*h;
	h=(int *)calloc(nc,sizeof(int));
	for(i=0;i<nc;i++)
		h[i]=0;
	while(s!=am)
 	{
  		x=add(s,am);
  		if(x==-2)
  		{
  			printf("Total amount is %d less than amount required!!!",am-s);
  			return;
  		}
		if(x!=-1)
  		{
   			h[x]++;
   			s=s+c[x].v;
  		}
 	}
	printf("\nCoin | Number");
	for(i=0;i<nc;i++)
	{
		printf("\n%4d | %5d",c[i].v,h[i]);
	}
}
int add(int s,int n)
{
	int i;
	for(i=nc-1;i>-1;i--)
	{
		if((s+c[i].v)<=n&&c[i].n>0)
		{
			c[i].n--;
			return i;
		}
	}
	for(i=nc-1;i>-1;i--)
		if(c[i].n>0)
 			return -1;
 	return -2;
}

#include<stdio.h>
#include<conio.h>
struct tab
{
	float w,p,r;
}*k;
float c;
int n;
void selection(struct tab *,int);
void main() 
{
	int i,j;
	printf("\nEnter the no. of objects:- ");
	scanf("%d",&n);
	k=(struct tab *)calloc(n,sizeof(struct tab));
	printf("\nEnter the weigth & profits of each object:- ");
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&k[i].w,&k[i].p);
		k[i].r=k[i].p/k[i].w;
	}
	printf("\nEnter the capacity of knapsack:- ");
	scanf("%f",&c);
	selection(k,n);
   	knapsack();
}
void selection(struct tab *q,int x)
{
	int i,j,k;
	float t;
	for(i=0;i<x-1;i++)
		{
			k=i+1;
			for(j=i+2;j<x;j++)
				if((q+k)->r<(q+j)->r)
					k=j;	
			if((q+i)->r<(q+k)->r)
				{
					t=q[k].r;
					q[k].r=q[i].r;
					q[i].r=t;
					t=q[k].w;
					q[k].w=q[i].w;
					q[i].w=t;
					t=q[k].p;
					q[k].p=q[i].p;
					q[i].p=t;
				}
		}
}
void knapsack()
{
	float *x,tp=0;
	int i,j;
	x=(float *)calloc(n,sizeof(float));
	for(i=0;i<n;i++)
      	x[i]=0.0;
	for(i=0;i<n;i++)
	{
    	if(k[i].w>c)
        	break;
    	else
		{
	       	x[i]=1.0;
         	tp=tp+k[i].p;
         	c=c-k[i].w;
      	}
   	}
   	if(i<n)
		x[i]=c/k[i].w;
	tp=tp+(x[i]*k[i].p);
	printf("\nThe result vector is:- ");
	for(i=0;i<n;i++)
		printf("\n%f",x[i]);
	printf("\nMaximum profit is:- %f",tp);
}

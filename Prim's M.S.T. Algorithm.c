#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int nv,ne,pw=0,nuv=0,*u;
struct neel
{
	int x,w;
	struct neel *y;
}*first;
void edges();
struct neel * insend(int,int,struct neel *);
void vertices();
int getnext(struct neel **);
void prim();
void main()
{
vertices();
edges();
u=(int*)calloc(nv,sizeof(int));
u[0]=0;
nuv=1;
prim();
display();
printf("\nTotal Weight of Minimum Spanning Tree :- %d",pw);
getch();
}
struct neel * insend(int a,int b,struct neel *f)
{
	struct neel *p;
	if(f==NULL)
	{
		f=(struct neel*)malloc(sizeof(struct neel));
		f->x=a;
		f->w=b;
		f->y=NULL;
		return f;
	}
	p=f;
	for(;p->y!=NULL;)
		p=p->y;
	p->y=(struct neel*)malloc(sizeof(struct neel));
	p=p->y;
	p->x=a;
	p->w=b;
	p->y=NULL;	
	return f;
}
void vertices()
{
	int i;
	printf("enter the number of vertices...");
	scanf("%d",&nv);
	first=(struct neel*)calloc(nv,sizeof(struct neel));
	for(i=0;i<nv;i++)
	{
		printf("\nenter %d vertex..",i+1);
		scanf("%d",&(first+i)->x);
	}
}
void edges()
{
	int h,x,y,z;
	printf("enter number of edges...");
	scanf("%d",&ne);
	for(h=0;h<ne;h++)
	{
		printf("\nenter starting , ending vertices & weight of %d edge..",h+1);
		scanf("%d %d %d",&x,&y,&z);
		{
			int t,u;
			if(!search(x,first,nv))
			{
				printf("enter valid vertices..");
				h--;
				continue;
			}
			for(t=0;(first+t)->x!=x;t++);
			if(!search(y,first,nv))
			{
				printf("enter valid vertices..");
				h--;
				continue;
			}
			for(u=0;(first+u)->x!=y;u++);
			insend(y,z,first+t);
			insend(x,z,first+u);
		}
	}
}
int search(int z,struct neel *f,int l)
{
	int i;
	for(i=0;i<l;i++)
		if((f+i)!=NULL&&((f+i)->x==z))
			return 1;
	return 0;	
}
void prim()
{
	struct neel *p;
	printf("      ");
	if(!getnext(&p))
		return;
	u[nuv++]=getindex(p)-1;
	pw=pw+p->w;
	prim();
}
int getnext(struct neel **f)
{
	int i,j,k;
	struct neel *g,*h,*nw;
	if(nv==nuv)
		return 0;
	for(i=0;i<nuv;i++)
	{
		g=(first+u[i]);
		for(;g!=NULL;)
		{
			if((nw==NULL&&g->w>0)||(nw!=NULL&&g->w<nw->w))
			{
				k=1;
				for(j=0;j<nuv;j++)
				{
					if(g->x==(first+u[j])->x)
						k=0;
				}
				if(k)
					nw=g;
			}
			g=g->y;
		}
	}
	*f=nw;
	return 1;	
}
int getindex(struct neel *p)
{
	int i;
	for(i=1;i<=nv;i++)
	{
		if(p->x==(first+i-1)->x)
			return i;
	}
	return 0;
}

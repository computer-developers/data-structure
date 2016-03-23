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
int getnext(struct neel **,struct neel **);
void kruskal();
void display();
void main()
{
vertices();
edges();
u=(int*)calloc(nv,sizeof(int));
//u[0]=0;
//nuv=1;
kruskal();
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
void display()
{
	struct neel *p;
	int i;
	for(i=0;i<nv;i++)
	{
		p=first+i;
		printf("\n");
		for(;p!=NULL;)
		{
			printf("(%d)->%d",p->w,p->x);
			p=p->y;
		}
	}
}
void kruskal()
{
	struct neel *p1,*p2;
	int k;
	printf("\ncheck 1..");
	k=getnext(&p1,&p2);
	if(!k)
		return;
	printf("\ncheck 2..");
	u[nuv++]=getindex(p1)-1;
	printf("\ncheck 3..");	
	if(k==2)
		u[nuv++]=getindex(p2)-1;
	printf("\ncheck 4..");
	pw=pw+p1->w;
	kruskal();
	printf("\ncheck 5..");	
}
int getnext(struct neel **f,struct neel **f1)
{
	int i,j,k;
	printf("\ncheck 6..");
	struct neel *g,*h,*nw;
	printf("\ncheck 7..");
	if(nv==nuv)
		return 0;
	printf("\ncheck 8..");
	for(i=0;i<nv;i++)
	{
		printf("\ncheck 9..");
		h=(first+i);
		g=h;
		printf("\ncheck 10..");
		for(;g!=NULL;)
		{
			printf("\ncheck 11..");
			if((nw==NULL&&g->w>0)||(nw!=NULL&&g->w<nw->w))
			{
				k=1;
				printf("\ncheck 12..");
				for(j=0;j<nuv;j++)
				{
					if(g->x==(first+u[j])->x||h->x==(first+u[j])->x)
						k=0;
				}
				if(k)
					nw=g;
			}
			printf("\ncheck 1..");
			g=g->y;
		}
	}
	*f=nw;
	k=1;
	for(j=0;j<nuv;j++)
	{
		if(h->x==(first+u[j])->x)
			k=0;
	}
	if(k)
	{
		*f1=h;
		return 2;
	}
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

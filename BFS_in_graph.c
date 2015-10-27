#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int nv,ui=0,ne;
struct neel
{
	int x;
	struct neel *y;
}*first,*s,*u;
void edges();
int ifexist(int,struct neel *);
struct neel * insend(int,struct neel *);
void vertices();
int search(int,struct neel *,int);
int getnext(struct neel **);
void bfs();
void main()
{
vertices();
edges();
s=insend(first->x,s);
printf("\nBreadth First Search sequence :- ");
bfs();
getch();
}
struct neel * insend(int a,struct neel *f)
{
	struct neel *p;
	if(f==NULL)
	{
		f=(struct neel*)malloc(sizeof(struct neel));
		f->x=a;
		f->y=NULL;
		return f;
	}
	p=f;
	for(;p->y!=NULL;)
		p=p->y;
	p->y=(struct neel*)malloc(sizeof(struct neel));
	p=p->y;
	p->x=a;
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
	int h,x,y;
	printf("enter number of edges...");
	scanf("%d",&ne);
	for(h=0;h<ne;h++)
	{
		printf("\nenter starting & ending vertices of %d edge..",h+1);
		scanf("%d %d",&x,&y);
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
			insend(y,first+t);
			insend(x,first+u);
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
void bfs()
{
	struct neel *p;
neel:if(!getnext(&p))
		return;
	if(ifexist(p->x,u))
		goto neel;
	printf("%d ",p->x);
	u=insend(p->x,u);
	p=p->y;
	for(;p!=NULL;)
	{
		s=insend(p->x,s);	
		p=p->y;
	}
	p=NULL;
	bfs();
}
int getnext(struct neel **f)
{
	int i;
	if(s==NULL)
		return 0;
	for(i=0;(first+i)->x!=s->x;i++);
	*f=first+i;
	s=s->y;
	return 1;	
}
int ifexist(int a,struct neel *p)
{
	for(;p!=NULL;)
	{
		if(p->x==a)
			return 1;
		p=p->y;
	}
	return 0;
}

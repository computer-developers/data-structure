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
struct neel * insend(int a,struct neel *);
void vertices();
void display();
int getnext(struct neel **);
void bfs();
void main()
{
vertices();
edges();
display();
s=insend(first->x,s);
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
		printf("%d->",p->x);
		p=p->y;
	}
	}
}
void bfs()
{
	printf("check point 1...\n");
	struct neel *p,*t;
	t=s;
	for(;t!=NULL;)
	{
		printf("s:%d - ",t->x);
		t=t->y;
	}
neel:if(!getnext(&p))
		return;
	//printf("check point 5...\n");
	if(ifexist(p->x,u))
		goto neel;
	t=p;
	for(;t!=NULL;)
	{
		printf("p:%d - ",t->x);
		t=t->y;
	}
	//printf("check point 6...\n");
	printf("%d->",p->x);
	u=insend(p->x,u);
	printf("check point 9...\n");
	t=u;
	for(;t!=NULL;)
	{
		printf("u:%d - ",t->x);
		t=t->y;
	}
	p=p->y;
	for(;p!=NULL;)
	{
		printf("check point 12...\n");
		s=insend(p->x,s);	
		printf("check point 11-%d...\n",p->x);
		p=p->y;
	}
	//printf("check point 10...\n");
	p=NULL;
	printf("check point 2...\n");
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
	//printf("check point 7...\n");
	for(;p!=NULL;)
	{
		if(p->x==a)
			return 1;
		p=p->y;
	}
	//printf("check point 8...\n");
	return 0;
}

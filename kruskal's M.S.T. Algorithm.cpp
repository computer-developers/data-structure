#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
struct tab
{
	int v1,v2,w;
};
class stack
{	
private: int t=-1,i;
		struct neel
		{
			int x;
			struct neel *y;
		}*s=NULL;
		struct neel * insert(int a,struct neel *f)
		{
			struct neel *p;
			p=(struct neel *)malloc(sizeof(struct neel));
			p->x=a;
			p->y=f;
			return p;			
		}
		struct neel * del(struct neel *f,int *g)
		{
			if(f==NULL)return NULL;
			*g=f->x;
			return f->y;
		}
public: 
	int push(int x)
	{
		t++;
		s=insert(x,s);
		return 1;
	}
	
	int pop()
	{	
		int g;
		if (t==-1) return 0;
		t--;
		s=del(s,&g);
		return g;
	}
	
	void display()
	{
		struct neel *p;
		if(s==NULL)return;
		p=s;
		printf("\n");
		for(;p!=NULL;)
		{
			printf("%d ",p->x);
			p=p->y;
		}
	}
	
	int search(int a)
	{
		int i;
		struct neel *p;
		p=s;
		for(i=1;p!=NULL&&p->x!=a;i++)
			p=p->y;
		if(p!=NULL&&p->x==a)
			return i;
		else
			return 0;
	}
};
class graph
{
private:
	int nv,ne;
	stack firstv;
	void vertices()
	{
		int i,t;
		printf("enter the number of vertices...");
		scanf("%d",&nv);
		for(i=0;i<nv;i++)
		{
			printf("\nenter %d vertex..",i+1);
			scanf("%d",&t);
			firstv.push(t);
		}
	}
	
	void edges()
	{
		int h,x,y,z,t;
		printf("enter number of edges...");
		scanf("%d",&ne);
		firste=(struct tab*)calloc(ne,sizeof(struct tab));
		for(h=0;h<ne;h++)
		{
			printf("\nenter starting , ending vertices & weight of %d edge..",h+1);
			scanf("%d %d %d",&x,&y,&z);
			{
				int t,u;
				if(!firstv.search(x))
				{
					printf("enter valid vertices..");
					h--;
					continue;
				}
				if(!firstv.search(y))
				{
					printf("enter valid vertices..");
					h--;
					continue;
				}
				(firste+h)->v1=x;
				(firste+h)->v2=y;
				(firste+h)->w=z;
			}
		}
	}	

public:
	struct tab *firste;
	void display()
	{
		int i;
		for(i=0;i<ne;i++)
			printf("\n%d %d %d",(firste+i)->v1,(firste+i)->v2,(firste+i)->w);
	}
	
	int getne()
	{
		return ne;
	}
	
	graph()
	{
		vertices();
		edges();
		printf("\nTable of edges..");
		display();
	}
};
class kruskal
{
private:
	int w=0;
	stack u;	
	graph g;
	void insertion(struct tab *p,int x)
	{
		int i,j,t,v11,v22,ww;
		for(i=0;i<x-1;i++)
		{
			for(j=i+1;j>0&&(p+j)->w<(p+j-1)->w;j--)
			{
				v11=(p+j-1)->v1;
				v22=(p+j-1)->v2;
				ww=(p+j-1)->w;
				(p+j-1)->v1=(p+j)->v1;
				(p+j-1)->v2=(p+j)->v2;
				(p+j-1)->w=(p+j)->w;
				(p+j)->v1=v11;
				(p+j)->v2=v22;
				(p+j)->w=ww;
			}
		}
	}

	void method(struct tab *p)
	{
		int i,l;
		l=g.getne();
		printf("\ncheck 1...");
		for(i=0;i<l;i++)
		{
			printf("\ncheck 2...");
			if(!u.search((p+i)->v1)||!u.search((p+i)->v2))
			{
				w=w+(p+i)->w;
				if(!u.search((p+i)->v1))
					u.push((p+i)->v1);
				if(!u.search((p+i)->v2))
					u.push((p+i)->v2);
			}
		}
	}
public:
	kruskal()
	{
		insertion(g.firste,g.getne());
		printf("\n\nTable of Edges after sorting according to weight..");
		g.display();
		method(g.firste);
		printf("\nTotal Weight of Minimum Spanning Tree is %d",w);
	}
};
int main()
{
	kruskal k;
	return 0;
}

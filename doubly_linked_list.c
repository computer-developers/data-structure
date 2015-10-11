#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert(int);
void insat(int,int);
void insend(int);
void display();
void del(int);
int ifempty();
struct neel
{
	int x;
	struct neel *f,*r;
}*first,*last;
void main()
{
	int z,p;
	printf("1.insert\n2.insend\n3.insat\n4.delete\n5.display\n6.exit\n");
	for(;1;)
	{
		printf("\nenter your choice..");
		switch (getche())
		{
			case '1':printf("\nenter element..");
					scanf("%d",&z);
					insert(z);
					break;
			case '2':printf("\nenter element..");
					scanf("%d",&z);
					insend(z);
					break;
			case '3':printf("\nenter element & place..");
					scanf("%d %d",&z,&p);
					insat(z,p);
					break;
			case '4':printf("\nenter element..");
					scanf("%d",&z);
					del(z);
					break;
			case '5':display();
					break;
			case '6':return;
			default:
				{
					printf("wrong choice!!!!");
				}

		}
	}
}
void insert(int a)
{
	struct neel *p;
	p=(struct neel *)malloc(sizeof(struct neel));
	p->r=first;
	p->f=NULL;
	p->x=a;
	first=p;
	if(p->r==NULL)last=p;
	else p->r->f=p;
}
void insend(int a)
{
	struct neel *p;
	p=(struct neel *)malloc(sizeof(struct neel));
	p->f=last;
	p->r=NULL;
	p->x=a;
	if(p->f==NULL)first=p;
	else
		last->r=p;
	last=p;
}
void insat(int a,int b)
{
	struct neel *p;
	p=(struct neel *)malloc(sizeof(struct neel));
	p->x=a;
	if(b==1)
		{
			insert(a);
			return;
		}
	p->r=first;
	for(;b>1&&p->r!=NULL;b--)
		{
			p->f=p->r;
			p->r=p->r->r;
		}
	if(b!=1)
		{
			printf("invalid place!!!");
			return;
		}
	p->f->r=p;
	if(p->r!=NULL)			
			p->r->f=p;
	else
		last=p;
}
void del(int a)
{
	struct neel *p;
	if(ifempty())return;
	p=first;
	if(p->x==a)
	{
		first=p->r;
		return;
	}
	for(;p->x!=a&&p->r!=NULL;)
		p=p->r;
	if(p->x!=a)
		{
			printf("\nelement not found!!!");
			return;
		}
	p->f->r=p->r;
	if(p->r!=NULL)
		p->r->f=p->f;
	else
		last=p->f;
}
void display()
{
	struct neel *p;
	if(ifempty())return;
	p=first;
	printf("\n");
	for(;p!=last;)
	{
		printf("%d ",p->x);
		p=p->r;
	}
	printf("%d",p->x);
}
int ifempty()
{
	if(first!=NULL)
		return 0;
	printf("Linked list is empty...");
	return 1;
}

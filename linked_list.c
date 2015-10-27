#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert(int);
void display();
void insend(int);
void insat(int);
void del(int);
void reverse();
void search(int);
void sort();
void count();
struct neel
{
	int x;
	struct neel *y;
}*first;
int main()
{
int z,p;
char c;
printf("1.insert\n2.insend\n3.insat\n4.delete\n5.reverse\n6.search\n7.sort\n8.count\n9.display\n0.exit\n");
for(;1;)
{
  printf("\nenter your choice ");
  c=getche();
  switch (c)
  {
  case '1':	printf("\nenter element..");
				scanf("%d",&z);
				insert(z);
				break;
  case '2':	printf("\nenter element..");
				scanf("%d",&z);
				insend(z);
				break;
  case '3':	printf("\nenter element..");
				scanf("%d",&z);
				insat(z);
				break;
  case '4':	printf("\nenter element..");
				scanf("%d",&p);
				del(p);
				break;
  case '5':	reverse();break;
  case '6':	printf("\nenter element..");
				scanf("%d",&p);
				search(p);
				break;
  case '7':	sort();break;
  case '8':	count();break;
  case '9':	display();break;
  case '0':	return 0;break;
  default:	printf("\nwrong choice!!!");
  }
} 
}
void insert(int a)
{
	struct neel *p;
	p=(struct neel *)malloc(sizeof(struct neel));
	p->x=a;
	p->y=first;
	first=p;	
}
void display()
{
	struct neel *p;
	if(ifempty())return;
	p=first;
	printf("\n");
	for(;p!=NULL;)
	{
		printf("%d ",p->x);
		p=p->y;
	}
}
void insend(int a)
{
	struct neel *p;
	p=first;
	if(p==NULL)
	{
		insert(a);
		return;
	}
	for(;p->y!=NULL;)
		p=p->y;
	p->y=(struct neel*)malloc(sizeof(struct neel));
	p=p->y;
	p->x=a;
	p->y=NULL;
} 
void del(int a)
{
	int i;
	struct neel *p,*t;
	if(ifempty())return;
	p=first;
	if(p->x==a)
		{
			p=p->y;
			free(first);
			first=p;
			return;
		}
	for(;p->y!=NULL&&p->y->x!=a;)
		p=p->y;
	if(p->y->x==a)
		{
			t=p->y;
			p->y=p->y->y;
			free(t);
		}
	else
		printf("\nelement not exist...");
}
void search(int a)
{
	int i;
	struct neel *p;
	if(ifempty())return;
	p=first;
	for(i=1;p!=NULL&&p->x!=a;i++)
		p=p->y;
	if(p->x==a)
		printf("\nplace of element is %d",i);
	else
		printf("\nelement not exist...");
}
void count()
{
	int a=1;
	struct neel *p;
	if(ifempty())return;
	p=first;
	for(;p->y!=NULL;a++)
		p=p->y;
	printf("\nnumber of element is %d",a);
}
void sort()
{
	struct neel *p,*q;
	p=first;
	if(ifempty())return;
	for(;p->y!=NULL;)
	{
		for(q=p->y;q!=NULL;)
		{
			if(p->x>q->x)
			{
				p->x=p->x+q->x;
				q->x=p->x-q->x;
				p->x=p->x-q->x;
			}
			q=q->y;
		}
		p=p->y;
	}
}
void insat(int a)
{
	struct neel *p,*q;
	sort();
	if(first->x>a)
	{
		insert(a);
		return;
	}
	q=first;
	p=(struct neel *)malloc(sizeof(struct neel));
	p->x=a;
	for(;q->y!=NULL&&q->y->x<p->x;)
		q=q->y;
	p->y=q->y;
	q->y=p;
}
int ifempty()
{
	if(first==NULL)
		{
			printf("linked list is empty..");
			return 1;
		}
	return 0;
}
void reverse()
{
	struct neel *p,*q,*f,*t;
	f=first;
	q=f;
	insert(q->x);
	t=q;
	q=q->y;
	free(t);
	first->y=NULL;
	for(;q!=NULL;)
	{
		insert(q->x);
		t=q;
		q=q->y;
		free(t);
	}
}

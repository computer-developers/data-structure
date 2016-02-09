/*
Designed by neel patel..
this program is written in dev-cpp & compiled by tdm-gcc 4.8.1 compiler
getche() used to eliminate garbage input.it can be replaced by scanf().
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct neel
{
	char x;
	struct neel *l,*r;
}*root,*p1;
int f1;
void insert(char,char);
struct neel * travers(char);
struct neel * inorder(struct neel *,char);
void preorder(struct neel *p);
void postorder(struct neel *p);
void main()
{
	char c,d;
	printf("enter root node..");
scanr:c=getche();
	if(!(isalpha(c)||('0'<=c&&c<='9')))
	{
		printf("\nonly alphabats & number is allowed!!!\n");
		goto scanr;
	}
	root=(struct neel *)malloc(sizeof(struct neel));
	root->x=c;
	root->l=NULL;
	root->r=NULL;
	printf("\nmenu\n1.insert\n2.inorder travers\n0.exit");
	for(;1;)
	{
		printf("\nenter your choice..\n");
		switch(getche())
		{
			case '1':printf("\nenter parent node & new node..");
					c=getche();
					printf("  ");
					d=getche();
					insert(c,d);
					break;
			case '2':travers('#');break;
			case '3':printf("\nPREORDER SEQUENCE :- ");
					preorder(root);
					break;
			case '4':printf("\nPOSTORDER SEQUENCE :- ");
					postorder(root);
					break;
			case '0':return;
					break;
			default:
				printf("wrong choice...");	
		}	
	}
getch();
}
void insert(char p,char c)
{
	char s;
	if(!(isalpha(c)||('0'<=c&&c<='9')))
	{
		printf("\nonly alphabats & number is allowed!!!\n");
		return;
	}
	struct neel *f;
	f=travers(p);
	if(f==NULL)
	{
		printf("\n%c not found!!",p);
		return;
	}
neel:printf("\nwhere you want to insert\n1.left\n2.right\n");
	s=getche();
	if(s=='1')
	{
		if(f->l!=NULL)
		{
			printf("\nleft link of %c is not available..\n",p);
			return;
		}
		else
		f->l=(struct neel *)malloc(sizeof(struct neel));
		f->l->x=c;
		f->l->l=NULL;
		f->l->r=NULL;
	}
	else if(s=='2')
	{
		if(f->r!=NULL)
		{
			printf("\nright link of %c is not available..\n",p);
			return;
		}
		else
		f->r=(struct neel *)malloc(sizeof(struct neel));
		f->r->x=c;
		f->r->l=NULL;
		f->r->r=NULL;
	}
	else
		goto neel;
	printf("\n%c is inserted..\n",c);
}
struct neel * travers(char a)
{
	p1=NULL;
	if(a!='#')
	{
		f1=0;
		return inorder(root,a);
	}
	f1=1;
	printf("\nINORDER SEQUENCE :- ");
	inorder(root,a);
	return NULL;
}
struct neel * inorder(struct neel *p,char c)
{
	if(p1!=NULL)
		return p1;
	if(p->l!=NULL)
		inorder(p->l,c);
	if(f1)
		printf("%c ",p->x);
	if(p->x==c)
	{
		p1=p;
		return p1;
	}
	if(p->r!=NULL)
		inorder(p->r,c);
	return p1;
}
void preorder(struct neel *p)
{
	printf("%c ",p->x);
	if(p->l!=NULL)
		preorder(p->l);
	if(p->r!=NULL)
		preorder(p->r);	
}
void postorder(struct neel *p)
{
	if(p->l!=NULL)
		postorder(p->l);
	if(p->r!=NULL)
		postorder(p->r);
	printf("%c ",p->x);
}

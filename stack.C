#include<stdio.h>
#include<conio.h>
int t=-1,a[5];
void push(int);
void pop();
void peep(int);
void change(int,int);
void display();
int main()
{
int z,p;
char c;
printf("1.push\n2.pop\n3.peep\n4.change\n5.display\n6.exit\n");
for(;1;)
{
  printf("\nenter your choice ");
  c=getche();
  switch (c)
  {
  case '1':	printf("\nenter element..");
				scanf("%d",&z);
				push(z);
				break;
  case '2':	pop();break;
  case '3':	printf("\nenter place from top..");
				scanf("%d",&p);
				peep(p);
				break;
  case '4':	printf("\nenter place & new value..");
				scanf("%d %d",&p,&z);
				change(z,p);
				break;
  case '5':	display();break;
  case '6':	return 0;break;
  default:	printf("\nwrong choice!!!");
  }
}
}
void push(int z)
{
if(t<4)
	{
		t++;
		a[t]=z;
	}
else
		printf("stack is full.\n");
}
void pop()
{
if(t>=0)
	t--;
else
	printf("\nno value in stack\n");
}
void peep(int p)
{
if((p-1)<=t)
printf("\n%d element from top is %d\n",p,a[t-p+1]);
else
printf("\nerror!!!!!\n");

}
void change(int z,int p)
{
if(t-p+1>=0&&p>0)
{
	a[t-p+1]=z;
	printf("\n%d element from top is %d\n",p,a[t-p+1]);
}
else
printf("\nnot possibl\n");

}
void display()
{
int x;
printf("\n");
for(x=0;x<=t;x++)
printf("%d\n",a[x]);
}

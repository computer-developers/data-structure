#include<stdio.h>
#include<conio.h>
int f=-1,r=-1,a[5];
void insertion(int);
void deletion();
void search(int);
void change(int,int);
void display();
int main()
{
int z,p;
char c;
printf("1.insertion\n2.deletion\n3.search\n4.change\n5.display\n6.quit\n");
for(;1;)
{
  printf("\nenter your choice ");
  c=getche();
  switch (c)
  {
  case '1':	printf("\nenter element..");
				scanf("%d",&z);
				insertion(z);
				break;
  case '2':	deletion();break;
  case '3':	printf("\nenter place from front..");
				scanf("%d",&p);
				search(p);
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
void insertion(int z)
{
if(r<4)
	{	
		r++;
		a[r]=z;
		if(f==-1)f++;
	}
else
		printf("queue is full.\n");
}
void deletion()
{
if(f>=0&&f<=r)
{
	f++;
	printf("\n%d is deleted..",a[f-1]);
}
else
	printf("\nno value in queue\n");
}
void search(int p)
{
if((p-1)<=r-f&&p>0)
printf("\n%d element from front is %d\n",p,a[f+p-1]);
else
printf("\nerror!!!!!\n");
}
void change(int z,int p)
{
if((p-1)<=(r-f)&&p>0)
{
	a[f+p-1]=z;
	printf("\n%d element from front is %d\n",p,a[f+p-1]);
}
else
printf("\nnot possible\n");

}
void display()
{
int x;
printf("\n");
for(x=f;x<=r;x++)
printf("%d\n",a[x]);
}

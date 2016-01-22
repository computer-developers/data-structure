#include<stdio.h>
#include<conio.h>
#include<iostream>
#define sz 5
class queue
{
	private:int s[sz],f=-1,r=-1;
	public:	int insert(int x)
			{
				if(r>=sz-1)
					return 0;
				r++;
				s[r]=x;
				if(f==-1)
					f++;
				return 1;
			}
			int del()
			{
				int i;
				if(f==-1)
					return 0;
				i=s[f];
				if(++f>r)
				{
					f=-1;
					r=-1;
				}
				return i;
			}
			void display()
			{
				int i;
				printf("\n");
				for(i=f;f!=-1&&i<=r;i++)
					printf("%d ",s[i]);
			}
};
class stack
{
	private:queue q1,q2;
	public:	void push(int x)
			{
				if(!x)
					printf("\n%d is not inserted!!!",x);
				if(!q1.insert(x))
					printf("\nstack overflow!!!!");
			}
			void pop()
			{
				int x,y;
				x=q1.del();
				y=q1.del();
				for(;y;)
				{
					q2.insert(x);
					x=y;
					y=q1.del();
				}
				if(x)
					printf("\n%d deleted\n",x);
				else
					printf("\nqueue under flow\n");
				x=q2.del();
				for(;x;)
				{
					q1.insert(x);
					x=q2.del();
				}	
			}
			void display()
			{	
				q1.display();
			}
};
int main()
{
	stack a;
	int z;
	printf("menu\n 1.insert\n 2.delete\n 3.display\n 0.exit\nenter choice...");
	for(;1;)
	{	switch(getche())
		{	case '1': printf("\n enter element to insert..");
					  scanf("%d",&z);
					  a.push(z);
					  break;
			case '2': a.pop(); break;
			case '3': a.display(); break;
			case '0': return 0; break;
			default : printf("\n wrong choice !!!!");		  	
		}
		printf("\nenter choice...");
	}
}


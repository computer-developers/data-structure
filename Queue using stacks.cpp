#include<stdio.h>
#include<conio.h>
#include<iostream>
#define sz 5
class stack
{	private: int s[sz],t=-1,i;
	public: int push(int x)
	{	if(t==sz-1) return 0;
		t++;
		s[t]=x;
		return 1;
	}
	int pop()
	{	if (t==-1) return 0;
		t--;
		return s[t+1];
	}
	void display()
	{	int i;
		printf("\n");
		for(i=0;i<=t;i++)
			printf("%d ",s[i]);
		printf("\n");
	}
};
class queue
{	private:stack s1,s2;
	public:void display()
	{	s1.display();
	}
	void insert(int x)
	{	if(!x)
			printf("\n%d can not be inserted in queue..\n",x);
		if(!s1.push(x))
			printf("\nqueue over flow!!!");
	}
	void del()
	{
		int x;
		x=s1.pop();
		for(;x;)
		{
			s2.push(x);
			x=s1.pop();
		}
		x=s2.pop();
		if(x)
			printf("\n%d deleted\n",x);
		else
			printf("\nqueue under flow\n");
		x=s2.pop();
		for(;x;)
		{
			s1.push(x);
			x=s2.pop();
		}		
	}
};
int main()
{
	queue a;
	int z;
	printf("menu\n 1.insert\n 2.delete\n 3.display\n 0.exit\nenter choice...");
	for(;1;)
	{	switch(getche())
		{	case '1': printf("\n enter element to insert..");
					  scanf("%d",&z);
					  a.insert(z);
					  break;
			case '2': a.del(); break;
			case '3': a.display(); break;
			case '0': return 0; break;
			default : printf("\n wrong choice !!!!");		  	
		}
		printf("\nenter choice...");
	}
}


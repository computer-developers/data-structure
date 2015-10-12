#include<conio.h>
#include<stdio.h>
int s[7];
void selection();
void main()
{
int i;
printf("\nenter 7 elements..");
for(i=0;i<7;i++)
	scanf("%d",&s[i]);
selection();
printf("\n");
for(i=0;i<7;i++)
	printf("%d ",s[i]);
getch();
}
void selection()
{
	int i,c,t;
	for(t=0;t<6;t++)
		{
			c=t+1;
			for(i=t+2;i<7;i++)
			{
				if(s[c]>s[i])
					c=i;
			}
			if(s[t]>s[c])
			{
				s[t]=s[t]+s[c];
				s[c]=s[t]-s[c];
				s[t]=s[t]-s[c];
			}
		}
}

#include<conio.h>
#include<stdio.h>
int s[7];
void bubble();
void main()
{
int i;
printf("\nenter 7 elements..");
for(i=0;i<7;i++)
	scanf("%d",&s[i]);
bubble();
printf("\n");
for(i=0;i<7;i++)
	printf("%d ",s[i]);
getch();
}
void bubble()
{
	int c=1,i;
	for(;c!=0;)
		{
			c=0;
			for(i=0;i<6;i++)
			{
				if(s[i]>s[i+1])
				{
					s[i]=s[i]+s[i+1];
					s[i+1]=s[i]-s[i+1];
					s[i]=s[i]-s[i+1];
					c++;
				}
			}
		}
}

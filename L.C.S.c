#include<stdio.h>
#include<string.h>
struct tab
{
	char d;
	int v;
}b[50][50];
int l1,l2;
char s1[50],s2[50];
void display(int i,int j)
{
    if(i==0 || j==0)
    	return;
	if(b[i][j].d=='c')
    {
    	display(i-1,j-1);
    	printf("%c",s1[i-1]);
    }
    else if(b[i][j].d=='u')
    	display(i-1,j);
    else
    	display(i,j-1);
}
 
void method()
{
	int i,j;
	l1=strlen(s1);
    l2=strlen(s2);
	for(i=0;i<=l1;i++)
    	b[i][0].v=0;
	for(i=0;i<=l2;i++)
   	    b[0][i].v=0;                            
    for(i=1;i<=l1;i++)
		for(j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
            {
				b[i][j].v=b[i-1][j-1].v+1;
                b[i][j].d='c';
            }
            else if(b[i-1][j].v>=b[i][j-1].v)
            {
                b[i][j].v=b[i-1][j].v;
                b[i][j].d='u';
            }
            else
	        {
                b[i][j].v=b[i][j-1].v;
				b[i][j].d='l';
            }
        }
}
int main()
{
	printf("Enter 1st sequence:");
    scanf("%s",s1);
    printf("Enter 2nd sequence:");
    scanf("%s",s2);
    printf("\nThe Longest Common Subsequence is ");
    method();
    display(l1,l2);
    return 0;
}

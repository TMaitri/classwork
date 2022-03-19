#include<stdio.h>
int main()
{
    int n1,n2,c;
    printf("Enter two numbers:");
    scanf("%d %d",&n1,&n2);
    max(n1,n2,&c);
    printf("The largest number is %d",c);
}
void max(int n1,int n2,int *c)
{
    if(n1>n2)
        *c=n1;
    else
        *c=n2;
}

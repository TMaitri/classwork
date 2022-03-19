#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter two numbers:");
    scanf("%d %d",&a,&b);
    add(a,b,&c);
    printf("%d",c);
}
void add(int a,int b, int *c)
{
    *c = a+b;
}

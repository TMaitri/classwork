#include<stdio.h>
int palindrome(int n);
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    palindrome(n);
}
int palindrome(int n)
{
    int t,s,r;
    t=n;
    while(n>0)
    {
        r=n%10;
        s=(s*10)+r;
        n=n/10;
    }
    if(s==t)
        printf("Palindrome");
    else
        printf("Not a palindrome");
}

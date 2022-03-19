#include<stdio.h>
int main()
{
    int r;float a;
    printf("Enter the radius:");
    scanf("%d",&r);
    area(r,&a);
    printf("Area of circle is %f",a);
}
void area(int r,float *a)
{
    *a = 3.14*r*r;
}

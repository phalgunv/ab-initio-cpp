#include<stdio.h>
#include<stdlib.h>

int compare(const void *x, const void *y)
{
   int result = *(int*)y - *(int*)x;
   return result;
}

int main(void)
{

    int a[10];
    int n = 0;
    while(scanf("%d",&a[n]) != EOF)
        n++;

    qsort(a, n, sizeof(int), compare);

    printf("The elements are:\n");
    while(n--)
        printf("%d ", a[n]);

    return 0;

} 

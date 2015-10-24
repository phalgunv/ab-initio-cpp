#include<stdio.h>
#define max(a, b)((a) > (b)?(a):(b))
main()
{
int a=4, c = 5;
printf("%d ", max(a++, c++));
printf("%d %d\n", a,c);
int num[3][4]=
{
{3,6,9,12},
{15,25,30,35},
{66,77,88,99}
};

printf("%d\n", *(*(num+1)));
printf("%d\n",*(*(num+1)+1)+1);
        

/*int arr[10];
int x = sizeof(arr);
printf("%d\n",x);*/
return 0;


}

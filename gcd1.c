#include <stdio.h>

int main()
{
    int t = 0;
    int i,j,n;
    scanf("%d",&t);
    long long g = 0;
	    
    for(i = 0; i < t; i++)
    {
    	scanf("%ld%ld", &g, &n);
        	
    	for(j = 0; j < n; j++)
    	{
            printf("\n j = %d", j);
    	}
    	
    }
    return 0;
}


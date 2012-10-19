#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fibonacci(int n);


int main(int argc, char** argv)
{
	int k=0;
	
	printf("Input k: ");
	scanf("%d", &k);
	printf("x_k = %d\n", fibonacci(k));

	return EXIT_SUCCESS;
}

int fibonacci(int n)
{
    int prevPrev=0, prev=1, i=0;
    int result=0;
        
	if (n == 0) return 0;
    if (n == 1) return 1;
        
    for (i=2; i<=n; i++)
    {
        result = prev + prevPrev;
        prevPrev = prev;
        prev = result;
    }
    return result;	
}

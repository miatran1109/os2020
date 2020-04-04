#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

void *printPrime(void *n) 
{
	int i=(int)(long long int)n;
	for (i=2; i < n; i++) 
    {
        bool prime=true;
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
            {
                prime=false;
                break;    
            }
        }   
        if(prime) 
		printf("%d",i);
    }
}

void *printFibonacci(void *n)
{
	static int n1=0,n2=1,n3;  
    if(n>0)
	{  
        n3 = n1 + n2;  
        n1 = n2;  
        n2 = n3;  
        printf("%d ",n3);  
        printFibonacci(n-1);  
	}
}

void main()
{
	int n = 1000000;
	pthread_t thread_1;
	pthread_t thread_2;

    printf("\nPrime thread:\n");
    pthread_create(&thread_1, NULL, printPrime, n);
    pthread_join(thread_1, (void *)&n);

	printf("\nFibonacci thread:\n");
	pthread_create(&thread_2, NULL, printFibonacci, n);
	pthread_join(thread_2, (void *)&n);
}



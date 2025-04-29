#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int num){
    bool prime = true;
    int end=(int)sqrt((double)num);
    for(int i=2; i<=end;i++)
    {
        if(num % i == 0)
        {
            prime=false;
        }
    }
}
int main()
{
    int num;
    scanf("%d",&num); 
    
    if(is_prime(num)){
        printf("the number is prime");
    }
    else{
        printf("the number is not prime");
    }
    return EXIT_SUCCESS;
}
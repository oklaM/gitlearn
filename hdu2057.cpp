#include <stdio.h>
typedef unsigned long long int ulli;

int main(){
    ulli a,b,c;
    while(~scanf("%llX %llX", &a, &b)){
        if(a+b>0xfffffffffffffff){
           c=-a-b;
            printf("-%llX\n",c);
        } 
        else{ c=a+b;
        printf("%llX\n", c);
        }
    }
    return 0;
}
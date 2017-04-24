#include <stdio.h>
#include <cmath>
int main(){
    int n,m;
    while(scanf("%d %d", &n, &m) && n!=0 && m!=0){
        int a=2*sqrt(m);
        do{
            if(m/a+a/2<=n)
            if(a%2==0 && ((double)m/a-m/a==0.5)){
                if(m/a-a/2+1>0)
                printf("[%d,%d]\n", m/a-a/2+1,m/a+a/2);
            }
            else if(a%2==1 && m%a==0){
                if(m/a-a/2>0)
                printf("[%d,%d]\n", m/a-a/2, m/a+a/2);
            }
        }while(--a);
        printf("\n");
    }
    return 0;
}
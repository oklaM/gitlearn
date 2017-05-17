#include <cstdio>

using namespace std;

int gcd(int a, int b){
    int temp;
    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int ans(int a, int b){
    int temp;
    temp=b / gcd(a, b) ;
    return temp;
}

int main(){
    int x, n;
    while(scanf("%d %d", &x, &n)!=EOF){
        for(int i=2; i<=n; ++i){
            
            printf("%d\n", ans(x, i));
        }
    }
    return 0;
}
#include <cstdio>
int fk(int n);
int f0(int n);
int f5(int n);

int fk(int n){
    return f0(n)+ f5(n);
}
int f0(int n){
    if(n<10) return 0;
    int t=n/10;
    return t;
}
int f5(int n){
    if(n<5) return 0;
    if(n<10) return 1;
    int t=2*n/10;

    return f0(n+5)+f5(t);
}

int main(){
    int n,ans=0;
    while(scanf("%d", &n)!=EOF){
        ans=fk(n);
        printf("%d\n", ans);
        ans=0;
    }
    return 0;
}
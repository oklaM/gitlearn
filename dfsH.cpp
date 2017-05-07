#include <cstdio>
#include <cmath>
const int maxn=pow(2,10)+1000;
int a[maxn],ans=0,max=0,tree[maxn]={0,0};

void dfs(int begin, int end){
    if(begin==end) return;
    int mid=(begin+end)/2;
    int tmax=0;
    for(int i=begin; i<end; ++i) if(tmax<a[i]) tmax=a[i];
    int t=max-tmax;
    if(t){
        ans=ans+t;
        for(int i=begin; i<end; ++i)
        a[i]=a[i]+t;
    }
    dfs(begin, mid);
    dfs(mid, end);
}

int main(){
    int n;

    while(scanf("%d", &n)!=EOF){
        const int N=pow(2,n),M=pow(2,n+1);
         ans=0, max=0;
        for(int i=2; i<M; ++i){
            scanf("%d", &tree[i]);
        }
        for(int i=0; i<N; ++i){
            a[i]=tree[N+i];
        }
        for(int i=0, tmp; i<N; ++i){
            tmp=N+i;
            while(tmp/2!=0){
                a[i]+=tree[tmp/2];
                tmp=tmp/2;
            }
            if(a[i]>max) max=a[i];
        }
        dfs(0,N);
        printf("%d\n", ans);
    }
    return 0;
}
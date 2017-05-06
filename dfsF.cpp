#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;    
const int maxn=100000+10;
int dis[maxn];

int main(){
    int t;
    while(scanf("%d", &t)!=EOF)
    while(t--){
        int n,d,x,y,ans=0;
        memset(dis, 0, sizeof(dis));
        scanf("%d %d", &n, &d);
        for(int i=0; i<n-1; ++i){
            scanf("%d %d", &x, &y);
            dis[y]=dis[x]+1;
        }
        sort(dis,dis+n);
        for(int i=n-1; dis[i]>d; --i) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
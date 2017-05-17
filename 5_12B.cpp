#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1000+5;
int visit[maxn], T, n, m, k, temp, ans;
struct node{
    int l, r, t;
    bool operator <(const node& n){
        if(l<n.l && r>n.r) return false;
        if(l==n.l) return r<n.r;
        else return l<n.l;
    }
}nodes[maxn];

int main(){
    while(scanf("%d", &T)!=EOF){
        int Case=0;
        while(T--){
            ++Case;
            ans=0;
            bool ok=true;
            scanf("%d %d %d", &n, &m, &k);
            memset(visit, 0, sizeof(visit));
            while(k--){
                scanf("%d", &temp);
                visit[temp]=1;
            }
            for(int i=1; i<=m; ++i){
                scanf("%d %d %d", &nodes[i].l, &nodes[i].r, &nodes[i].t);
                if(nodes[i].r-nodes[i].l+1 < nodes[i].t) ok=false;
            }
            if(ok){
            sort(nodes+1, nodes+m+1);
            int cnt, need;
            for(int i=1; i<=m; ++i){
                cnt=0; need=0;
                for(int j=nodes[i].l; j<=nodes[i].r; ++j){
                    cnt+=visit[j];
                }
                if(nodes[i].t > cnt)
                need=nodes[i].t-cnt;
                ans+=need;
                for(int k=nodes[i].r; need && k>=nodes[i].l; --k){
                    if(!visit[k]){
                        visit[k]=1;
                        --need;
                    }
                }               
            }
            }else ans=-1;
            printf("Case %d: %d\n", Case, ans);
        }
    }
    return 0;
}
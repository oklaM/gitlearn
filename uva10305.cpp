#include <cstdio>
#include <cstring>

const int maxn=100+5;
bool G[maxn][maxn];
int c[maxn];
int topo[maxn], t, n, m, a, b;

bool dfs(int u){
    c[u]=-1;
    for(int v=1; v<=n; ++v){
        if(G[u][v]){
            if(c[v]<0) return false;
            else if(!c[v] && !dfs(v)) return false; 
        }
    }
    c[u]=1; topo[t--]=u;
    return true;
}

bool toposort(){
    t=n;
    memset(c, 0, sizeof(c));
    for(int u=1; u<=n; ++u) if(!c[u])
        if(!dfs(u)) return false;
    return true;
}

int main(){
    while(scanf("%d%d", &n, &m)==2 && (n || m)){ //这里是m或n，与的话会wa; 
        memset(G, 0, sizeof(G));
        for(int i=0; i<m; ++i){
            scanf("%d%d", &a, &b);
            G[a][b]=1;
        }
        toposort();
        for(int i=1; i<n; ++i)
        printf("%d ", topo[i]);
        printf("%d\n", topo[n]);
    }
    return 0;
}
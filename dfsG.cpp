#include <cstdio>
#include <string.h>

const int moves[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
char dots[55][55],travel[55][55];
bool ans;
int n, m;

int cDir(int dir){
    if(dir==1) return 0;
    if(dir==0) return 1;
    if(dir==2) return 3;
    if(dir==3) return 2;
}
void dfs(int i, int j, char c, int cnt, int dir){
    if(ans) return;
    if(travel[i][j]==c && cnt>=4){ ans=true; return ;}
    if(travel[i][j]==' ' && dots[i][j]==c){
        travel[i][j]=c;
        for(int k=0,ii,jj; k<4; ++k){
            ii=i+moves[k][0];
            jj=j+moves[k][1];
            if(ii>=0 && ii<n && jj>=0 && jj<m)
            if(cDir(dir)!=k)
            dfs(ii, jj, c, cnt+1, k);
        }
    }
}

int main(){
    while(scanf("%d %d", &n, &m)!=EOF){
        ans=0;
        memset(travel,' ',sizeof(travel));
        for(int i=0; i<n; ++i)
            scanf("%s", dots[i]);
        for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j){
            dfs(i, j, dots[i][j], 0, 0);
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
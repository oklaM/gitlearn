#include <cstdio>
char tiles[25][25];
const int moves[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int ans, h, w;

void dfs(int i, int j){
    if(tiles[i][j]=='#') return;
    ++ans;
    for(int k=0; k<4; ++k){
        int ii=i+moves[k][0];
        int jj=j+moves[k][1];
        if(tiles[ii][jj]=='.' && ii>=0 && ii<h && jj>=0 && jj<w){
            tiles[ii][jj]='@';
            dfs(ii, jj);
        }
    }
}

int main(){
    while(scanf("%d %d", &w, &h)!=EOF && h && w){
        for(int i=0; i<h; ++i) scanf("%s", &tiles[i]);
        int x,y;
        ans=0;
        for(int i=0; i<h; ++i)
        for(int j=0; j<w; ++j)
        if(tiles[i][j]=='@'){x=i, y=j;}
        dfs(x, y);
        printf("%d\n", ans);
    }
}
#include <cstdio>
#include <algorithm>
#include <cstring>

char maze[16][16];
char ans[31],t[31];
bool tra[16][16];
int r,c;
int moves[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int i, int j, int len){
    if(maze[i][j]=='#') return;
    tra[i][j]=0;
    t[len]=maze[i][j];
    for(int k=0; k<4; ++k){
        int ii=i+moves[k][0];
        int jj=j+moves[k][1];
        if(tra[ii][jj] && ii>=0 && ii<r && ii>=0 && ii<c){
        dfs(ii, jj, len+1);
        tra[ii][jj]=1;
        }
        if(strlen(t)==len){
            if(strcmp(t,ans)>0){
                strcpy(ans, t);
            }
        }
    }
}

int main(){
    memset(tra, 0, sizeof(tra));
    while(scanf("%d %d\n", &r, &c)&& r && c){
        for(int i=0; i<r; ++i)
        for(int j=0; j<c; ++j)
        scanf("%c", &maze[i][j]), tra[i][j]=1;
  //      memset(ans, '\0', sizeof(ans));
        for(int i=0; i<r; ++i)
        for(int j=0; j<c; ++j)
        dfs(i, j, 0);
        printf("%s\n", ans);
    }
    return 0;
}
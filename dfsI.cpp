#include <cstdio>
#include <algorithm>
#include <cstring>

char maze[16][16];
char ans[31],t[31];
bool tra[16][16];
int r,c;

void dfs(int i, int j, int len){
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
                strcpy(ans, t, sizeof(ans));
            }
        }
    }
}

int main(){

    return 0;
}
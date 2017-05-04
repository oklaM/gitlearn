#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
    int r,c,ans;
    char board[22][22];
    bool visLetter[26],visPos[22][22];
    const int move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool judge(int i, int j){
    return (!visLetter[board[i][j]-'A'] && !visPos[i][j] && i>=0 && i<r && j>=0 && j<c);
}

void dfs(int i,int j, int cnt){
    visLetter[board[i][j]-'A']=visPos[i][j]=1;
    for(int k=0; k<4; ++k){
        int ii=i+move[k][0];
        int jj=j+move[k][1];
        if(judge(ii, jj)){
            dfs(ii, jj, cnt+1);
            visLetter[board[ii][jj]-'A']=visPos[ii][jj]=0;
        }
    }
    if(ans<cnt) ans=cnt;
}
int main(){
    cin>>r>>c;
    ans=1;
    memset(visLetter,false,sizeof(visLetter));
    memset(visPos, 0 , sizeof(visPos));
    for(int i=0; i<r; ++i)
        for(int j=0; j<c; ++j)
            cin>>board[i][j];
    dfs(0, 0, 1);
    cout<<ans<<endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
    int r,c,bm[22][22];
    char bl[22][22];
    bool d[26];
int dfs(int x, int y, int a){
    int left=0,right=0,up=0,down=0;
    if(d[bl[x+1][y]-'A']==0 && bm[x+1][y]==0){
        d[bl[x+1][y]-'A']=true;
        bm[x+1][y]=a;
        right=a;
        dfs(x+1, y, a+1);
    }
    if(d[bl[x-1][y]-'A']==0 && bm[x-1][y]==0){
        d[bl[x-1][y]-'A']=true;
        bm[x-1][y]=a;
        left=a;
        dfs(x-1, y, a+1);
    }
    if(d[bl[x][y+1]-'A']==0 && bm[x][y+1]==0){
        d[bl[x][y+1]-'A']=true;
        bm[x][y+1]=a;
        up=a;
        dfs(x, y+1, a+1);
    }
    if(d[bl[x][y-1]-'A']==0 && bm[x][y-1]==0){
        d[bl[x][y-1]-'A']=true;
        bm[x][y-1]=a;
        down=a;
        dfs(x, y-1, a+1);
    }
    return (max(left, right), max(up, down));    
}
int main(){
    cin>>r>>c;
    memset(d,false,sizeof(d));
    memset(bl, ' ', sizeof(bl));
    memset(bm, 0 , sizeof(bm));
    for(int i=1; i<=r; ++i)
        for(int j=1; j<=c; ++j)
            cin>>bl[i][j];
    int ans=dfs(1, 1, 1);
    cout<<ans<<endl;
    return 0;
}
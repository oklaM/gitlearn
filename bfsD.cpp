#include <cstdio>
#include <queue>

using namespace std;

const int maxn=500+5;
char maze[maxn][maxn];
const int dr[4]={1, 0, -1, 0};
const int dc[4]={0, 1, 0, -1};
int n, m, r1, c1, r2, c2;

bool BFS(){
    queue<int> qr, qc;
    qr.push(r1);
    qc.push(c1);
    while(!qr.empty()){
        int x=qr.front(); qr.pop();
        int y=qc.front(); qc.pop();
        for(int i=0; i<4; ++i){       
            int rr=x+dr[i];
            int cc=y+dc[i];
            if(rr==r2 && cc==c2 && maze[rr][cc]=='X') return 1;
            if(rr>0 && rr<=n && cc>0 && cc<=m && maze[rr][cc]=='.'){
                maze[rr][cc]='X';
                qr.push(rr);
                qc.push(cc);
            }
        }
    }
    return 0;
}

int main(){
    while(scanf("%d %d", &n, &m)!=EOF){
        for(int i=1; i<=n; ++i) scanf("%s", maze[i]+1);
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        if(BFS())
        printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
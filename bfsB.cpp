#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=100+5;
int visit[maxn][maxn];
char maze[maxn][maxn];
int n, m, ans;

struct Node{
    int x, y;
    Node(int x1, int y1):x(x1), y(y1){}
};

bool inside(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void BFS(int i, int j){
    visit[i][j]=1;
    Node node(i, j);
    queue<Node> q;
    while(!q.empty()) q.pop();
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int i=-1; i<2; ++i)
        for(int j=-1; j<2; ++j)
        {
            int x = node.x + i;
            int y = node.y + j;
            if(inside(x, y) && visit[x][y]==0 && maze[x][y]=='W'){
                visit[x][y]=1;
                Node next(x, y);
                q.push(next);
               // printf("%d %d\n", x, y);
                
            }
        }
    }
}

int main(){
    while(scanf("%d %d", &n, &m)!=EOF){
        ans=0;
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<n; ++i) scanf("%s", maze[i]);
        for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
        if(!visit[i][j] && maze[i][j]=='W')
        ++ans, BFS(i, j);
 //       else if(!visit[i][j] && maze[i][j]=='.')
//        visit[i][j]=1;
        printf("%d\n", ans);
    }
    return 0;
}

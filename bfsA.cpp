#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=200+5;
char maze[maxn][maxn];
int visit[maxn][maxn];
const int moves[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int n, m, ans, ai, aj;

struct Node{
    int x;
    int y;
    int step;
    Node(int x1, int y1, int step1):x(x1), y(y1), step(step1){}
    bool operator <(const Node& n) const{
        return step>n.step;//从小到大排队；
    }
};

bool inside(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int BFS(){
    for(int i=0, finda=0; i<n; ++i)if(finda) break; 
    else
    for(int j=0; j<m; ++j) if(maze[i][j]=='a'){ai=i, aj=j, finda=1; break;}
    memset(visit, 0, sizeof(visit));
    Node node(ai, aj, 0);
    priority_queue<Node> q;
    while(!q.empty()) q.pop();
    q.push(node);
    while(!q.empty()){
        node=q.top();
        q.pop();
        if(maze[node.x][node.y]=='r'){
            printf("%d\n", node.step);
            return 0;
        }
//        printf("%d\n", node.step);
        visit[node.x][node.y]=1;
        for(int k=0; k<4; ++k){
            int x= node.x + moves[k][0];
            int y= node.y + moves[k][1];
            if(inside(x, y) && visit[x][y]==0 && maze[x][y]!='#'){
                visit[x][y]=1;
                if(maze[x][y]=='r'){
                    printf("%d\n", node.step+1);
                    return 0;
                }
                else if(maze[x][y]=='.'){
                    Node next(x, y, node.step+1);
                    q.push(next);
                }
                else if(maze[x][y]!='#'){
                    Node kill(x, y, node.step+2);
                    q.push(kill);
                    //printf("%d\n", kill.step);
                }
            }
        }
    }
/*    for(int i=0; i<n; ++i) 
    for(int j=0; j<m; ++j){
        if(j==0) printf("\n");
        printf("%d ", visit[i][j]);
    }
*/
    printf("Poor ANGEL has to stay in the prison all his life.\n");
    return -1;
}

int main(){
    while(scanf("%d %d", &n, &m)!=EOF){
        for(int i=0; i<n; ++i) scanf("%s", maze[i]);
        BFS();
    }
    return 0;
}
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn=100000+10;
bool visit[maxn];
int n, m, ans;

struct Node{
    int x, step;
    Node(int x1, int step1):x(x1), step(step1){}
    Node(){}
    Node& operator ()(int x1, int step1){
        x=x1;
        step=step1;
        return *this;
    }
    Node& operator = (const Node & n1){
        x=n1.x;
        step=n1.step;
        return *this;
    }
};

int BFS(){
    memset(visit, 0, sizeof(visit));
    Node node(n, 0);
    Node next;
    queue<Node> q;
    visit[n]=1;
    while(!q.empty()) q.pop();
    q.push(node);
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(int i=0; i<3; ++i){
            if(i==0) next(node.x-1, node.step+1);
            else if(i==1) next(node.x+1, node.step+1);
            else if(i==2) next(node.x*2, node.step+1);
     //       printf("%d\n", next.x);
                    if(next.x==m) return next.step;
            if(next.x<0 || next.x>maxn) continue;
            if(!visit[next.x]){
                visit[next.x]=1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(){
    while(scanf("%d %d", &n, &m)!=EOF){
        if(m<n) printf("%d\n", n-m);
        else
        printf("%d\n", BFS());
    }
    return 0;
}
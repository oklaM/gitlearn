#include <bits/stdc++.h>  
using namespace std;  
  
int n,m,r1,c1,r2,c2;  
int dr[]= {1,0,-1,0};  
int dc[]= {0,1,0,-1};  
char c[505][505];  
  
bool bfs()  
{  
    queue <int> qx,qy;  
    qx.push(r1);  
    qy.push(c1);  
    while(!qx.empty())  
    {  
        int rr=qx.front();  
        int cc=qy.front();  
        qx.pop();  
        qy.pop();  
        for(int i=0; i<4; i++)  
        {  
            int tmpr=rr+dr[i];  
            int tmpc=cc+dc[i];  
            if(tmpr==r2&&tmpc==c2&&c[tmpr][tmpc]=='X')  
                return true;  
            if(tmpr>=1&&tmpr<=n&&tmpc>=1&&tmpc<=m&&c[tmpr][tmpc]=='.')  
            {  
                c[tmpr][tmpc]='X';  
                qx.push(tmpr);  
                qy.push(tmpc);  
            }  
        }  
    }  
    return false;  
}  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for(int i=1; i<=n; i++)  
    {  
        for(int j=1; j<=m; j++)  
        {  
            cin >>c[i][j];  
        }  
    }  
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);  
    if(bfs())  
        printf("YES\n");  
    else  
        printf("NO\n");  
    return 0;  
} 
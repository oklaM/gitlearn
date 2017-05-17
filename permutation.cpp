#include <cstdio>
#include <cstring>

int main(){
    int used[10];
    int a, b, c, d, e, f, g, h, i, abc, def, ghi;
    for(int a=1; a<=3; ++a){
        memset(used, 0, sizeof(used));
        used[0] = 1;
        used[a]=1;
        for(int b=1; b<10; ++b)
        if(used[b]==0){
            used[b]=1;
            for(int c=1; c<10; ++c)
            if(used[c]==0){
                used[c]=1;
                abc=a*100+b*10+c;
                def=2*abc;
                d=def/100;
                if(used[d]==0){
                    used[d]=1;
                    e=def/10%10;
                if(used[e]==0){
                    used[e]=1;
                    f=def%10;
                if(used[f]==0){
                    used[f] =1;
                    ghi=3*abc;
                if(ghi>987){
                    used[c]= used[d]= used[e]= used[f] =0;
                    continue;
                }
                g=ghi/100;
                if(used[g]==0){
                    used[g]=1;
                h=ghi/10%10;
                if(used[h]==0){
                    used[h]=1;
                i=ghi%10;
                if(used[i]==0){
                printf("%d %d %d\n", abc, def, ghi);
                }
                used[h] = 0;
                }
                used[g] = 0;
                }
                used[f] = 0;
                }
                used[e] = 0;
                }
                used[d] = 0;
                }
                used[c] = 0;
            }
            used[b]=0;
        }
    }
    return 0;
}
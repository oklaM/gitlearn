#include <cstdio>
#include <cstring>
using namespace std;

int power2(int x){
    int temp=1;
    return temp<<x;
}

int main(){
    char s[15];
    while(scanf("%s", s)!=EOF){

        int len=strlen(s);
        int ans=0, temp=0;
        temp=power2(len);
        ans+=temp-1;
        int temp1=len-1;
        for(int i=0; i<len; ++i, --temp1){
            if(s[i]=='7') ans+=power2(temp1);
        }
        printf("%d\n", ans);
        memset(s, '\0', sizeof(s));
    }
    return 0;
}
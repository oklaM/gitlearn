#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool l[26][26];
bool f[26];
bool ans;
char w[10010];
void dfs(char c){
    if(l[c-'a']['m'-'a']==1){ ans=true; return ;}
    f[c-'a']=0;
    for(int i=0; i<26; ++i){    
        if(l[c-'a'][i]==1 && f[i]==1 && !ans)
        dfs(i+'a');
    }
}

int main(){
            memset(l,0,sizeof(l));
            memset(f,1,sizeof(f));
    while(cin>>w){
        l[w[0]-'a'][w[strlen(w)-1]-'a']=1;
        if(w[0]=='0'){
            dfs('b');
            if(ans)cout<<"Yes."<<endl;
            else cout<<"No."<<endl;
            memset(l,0,sizeof(l));
            memset(f,1,sizeof(f));
            ans=0;
        }
        
    }
    return 0;
}
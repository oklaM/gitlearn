#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s; list<int> id[10000];int a,b;
    list<int>::iterator it;
    while(n--){
        cin>>s;
        if(s=="new"){
            cin>>a;
            id[a].clear();
        }
        if(s=="add"){
            cin>>a>>b;
            it=id[a].begin();
            id[a].insert(it,b);
            id[a].sort();
        }
        if(s=="merge"){
            cin>>a>>b;
            id[a].merge(id[b]);
        }
        if(s=="unique"){
            cin>>a;
            id[a].unique();
        }
        if(s=="out"){
            cin>>a;
            id[a].sort();
            for( it=id[a].begin();
            it!=id[a].end(); ++it)
            cout<<*it<<' ';
            cout<<endl;
        }
    }
    return 0;
}
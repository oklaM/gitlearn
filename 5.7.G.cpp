#include <cstdio>
#include <vector>
using namespace std;
int main(){
    vector<int> a;
    vector<int>::iterator it, mini;
    int n;
    while(scanf("%d", &n)!=EOF){
        a.clear();
        int t,k=0;
        for(int i=0; i<n; ++i){
            scanf("%d", &t);
            a.push_back(t);
        }
        while(!a.empty()){
            for(it=a.begin(), mini=a.begin() ; it!=a.end(); ++it){
                if(*it < *mini) mini=it;
            }
            k+=(mini-a.begin());
            a.erase(mini);
        }
        printf("%d\n", k);
    }
    return 0;
}
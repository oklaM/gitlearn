#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    vector<int> marble;
    int a,n,q,kase=0;
    while(scanf("%d %d", &n, &q) && n && q){
        marble.clear();
        for(int i=0; i<n; ++i){
            scanf("%d", &a);
            marble.push_back(a);
        }
        sort(marble.begin(), marble.end());
        printf("CASE# %d:\n", ++kase);
        for(int i=0; i<q; ++i){
            scanf("%d", &a);
            auto ans=find(marble.begin(), marble.end(), a);
            if(ans!=marble.end())
                printf("%d found at %d\n", a, ans-marble.begin()+1);
            else printf("%d not found\n", a);
        }
    }
    return 0;
}
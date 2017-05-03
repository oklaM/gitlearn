#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t,n,v;
    cin>>t;
    while(t--){
        int value[1010]={0},volume[1010]={0},ans[1010]={0};
        cin>>n>>v;
        for(int i=0; i<n; ++i)
            cin>>value[i];
        for(int i=0; i<n; ++i)
            cin>>volume[i];
        for(int i=0; i<n; ++i){
		    for(int j=v;j>=volume[i];j--)
		    ans[j]=max(ans[j],ans[j-volume[i]]+value[i]);
        }
        cout<<ans[v]<<endl;
    }
    return 0;
}

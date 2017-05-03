#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,coins[110],asum=0,bsum=0,ans=0,sum=0;
    cin>> n;
    for(int i=0; i<n; ++i){
        cin>>coins[i];
        sum+=coins[i];
    } 
    sort(coins, coins+n);
    bsum=sum;
    for(int i=n-1; i>=0; --i){
        asum+=coins[i];
        bsum-=coins[i];
        ++ans;
        if(asum>bsum) break;
    }
    cout<<ans<<endl;
    return 0;
}
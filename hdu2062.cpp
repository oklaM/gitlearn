#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    vector<int> lest;
    long long int t[21]={0,1,4},m;
    for(int i=3; i<20; ++i)
        t[i]=i*(t[i-1]+1);
    int n,k;//k记录当前位
    while(cin>>n>>m){
        lest.clear();
        for(int i=1; i<=n; ++i) lest.push_back(i);//存放还剩下的数字
        while(n--){
            k=(m-1)/(t[n]+1);
            cout<<lest[k];
            lest.erase(lest.begin()+k);
           // for(int i=0; i<lest.size(); ++i)
           // cout<< lest[i]<<' ';
            m=(m-1)%(t[n]+1);
            if(m==0) break;
            else cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int n,b,p,o;
    cin>>n;
    while(n--){
        cin>> b >> p >> o;
        if(b>6) p+=(b-6)*8+27;
        else p+=(15-b)*b/2;
        if(p>=o) cout<<"Yes"<<endl;
        else cout<< "No" <<endl;
    }
    return 0;
}
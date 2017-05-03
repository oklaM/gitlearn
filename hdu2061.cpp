#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n,k;
    double c[10000],s[10000];
    cin>>n;
    string cn;
    while(n--){
        bool sorry=false;
        double gpa=0,csum=0;
        cin>>k;
        for(int i=0; i<k; ++i){
            cin>>cn >>c[i] >>s[i];
            if(s[i]<60) sorry=true;
            gpa+=c[i]*s[i];
            csum+=c[i];
        }
    double g=(double)gpa/csum;
    if(sorry)cout<<"Sorry!"<<endl;
    else cout<<fixed<<setprecision(2)<<g<<endl;
    if(n>0)cout<<endl;
    }
    return 0;
}
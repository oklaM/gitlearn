#include <cstdio>
#include <cmath>

using namespace std;

bool isprime(int a){
    for(int i=2; i<sqrt(a); ++i){
        if(a%i == 0) return false;
    }
    return true;
}

int main(){
    int cnt=0;
    for(int i=1001; i<10000; ++i)
    if(isprime(i))
    cnt++;
    printf("%d\n", cnt);

    return 0;
}
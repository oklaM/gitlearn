#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxn=30;
vector<int> pile[maxn];

void find_block(int a, int & p, int & h){
    for(p=0; p<n; ++p)
        for(h=0; h<pile[p].size(); ++h)
            if(pile[p][h]==a) return;
}

void clear_above(int p, int h){
    for(int i=h+1; i<pile[p].size(); ++i){
        int b=pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}

void pile_onto(int p, int h, int p2){
    for(int i=h; i<pile[p].size(); ++i)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}

void print(){
    for(int i=0; i<n; ++i){
        cout<<i<<':';
        for(int j=0; j<pile[i].size(); ++j) cout<<' ' <<pile[i][j];
        cout<<endl;
    }
}
int main(){
    int a,b;
    cin>>n;
    string s1,s2;
    for(int i=0; i<n; ++i) pile[i].push_back(i);
    while(cin>> s1 >> a >> s2 >> b){
        int p1,p2,h1,h2;
        find_block(a, p1, h1);
        find_block(b, p2, h2);
        if(p1==p2) continue;
        if(s2=="onto") clear_above(p2,h2);
        if(s1=="move") clear_above(p1,h1);
        pile_onto(p1, h1, p2);
    }    
    print();
    return 0;
}
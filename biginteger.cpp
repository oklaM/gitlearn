#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

struct BigInteger {
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;

  BigInteger(long long num = 0) { *this = num; } // 构造函数
  BigInteger operator = (long long num) { // 赋值运算符
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0);
    return *this;
  }
  BigInteger operator = (const string& str) { // 赋值运算符
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for(int i = 0; i < len; i++) {
      int end = str.length() - i*WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end-start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return *this;
  }
  ~ BigInteger(){
    s.clear();
  }
  BigInteger operator = (const BigInteger& b){
    s.clear();
    for(int i=0; i<b.s.size(); ++i){
      s.push_back(b.s[i]);
    }
    return *this;
  }
  int getlen(){
    int g=s[s.size()-1];
    printf("%d\n", g);
    int len=1;
    g/=10;
    while(g>0){
      ++len;
      g/=10;
    }
    len+=(s.size()-1) * WIDTH;
    printf("%d\n", len);
    return len;
  }

  bool operator < (const BigInteger& b){
    if(s.size() != b.s.size())
      return s.size() < b.s.size();
    else {
      for(int i=s.size()-1; i>=0; ++i)
        if(s[i]!=b.s[i]) return s[i]<b.s[i];
    }
    return false;
  }
  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i++) {
      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if(i < s.size()) x += s[i];
      if(i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }
  BigInteger operator +=(const BigInteger& b){
    *this= *this + b;
    return *this;
  }
  BigInteger operator - (const BigInteger& b) {
      BigInteger c, d=b;
      int flag=0;
      if(*this < d){
        c= *this;
        *this= d;
        d= c;  //交换 使大减小；
        flag=1;
      }
      c.s.clear();
      for(int i=0, g=0, x=0, y=0; ; ++i){
          if(i >= s.size()) break;
          if(i >= d.s.size()) y=0;
          else y=d.s[i];
          x=s[i];
          if(g) --x;
          g=0;
          if(x<y){
            g=1;
            x+=BASE;
          }
          c.s.push_back(x - y);
      }
      if(flag)c.s.back()*=-1;
      return c;
  }
  BigInteger operator -= (const BigInteger& b){
    *this = *this - b;
    return *this;
  }
  BigInteger operator * (const BigInteger& b){
      BigInteger t;
      t.s.clear();
      long long g=0;
      BigInteger c;
      for(int i=0; i<b.s.size(); ++i){
        c.s.clear();
        for(int k=0; k<i; ++k) c.s.push_back(0);
        for(int j=0; j<s.size(); ++j){
              g+=(long long)b.s[i] * s [j];
              c.s.push_back(g % BASE);
              g/=BASE;
              if(j==s.size()-1)while(g>0){
                c.s.push_back(g % BASE);
                g/=BASE;
              }
        }
        t += c;
      }
      return t;
  }
  BigInteger operator *= (const BigInteger& b){
    *this= *this * b;
    return *this;
  }
  BigInteger operator / (const BigInteger& b){
      BigInteger c, d=*this, f=b, temp;
      const BigInteger ten(10);
      c.s.clear();
      d.s.clear();
   //   for(int i=s.size()-1; i>=0; --i){
   //     d.s.insert(d.s.begin(), s[i]);
   printf("%d\n", f.s[0]);
   printf("%d\n", d.s[1]);
   //     if(f<d){
          int n=getlen() - f.getlen();  
printf("%d\n", n);
          while(n>=0){
            temp=b;
            for(int j=0; j<n; ++j) temp*=ten;
      //    printf("%d\n", temp.s.back());      
            int addNum=0;
            while(temp<d){
              d -= temp;
              ++addNum;
      //                    printf("%d\n", addNum);
            }
            --n;
            BigInteger addnum(addNum);
            c= c * ten + addnum;
          }
    //    }
    //  }
      return c;
  }
};

ostream& operator << (ostream &out, const BigInteger& x) {
  out << x.s.back();
  for(int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%08d", x.s[i]);
    for(int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;
}

istream& operator >> (istream &in, BigInteger& x) {
  string s;
  if(!(in >> s)) return in;
  x = s;
  return in;
}

/*#include<set>
#include<map>
set<BigInteger> s;
map<BigInteger, int> m;*/

int main() {
//  BigInteger y;
//  BigInteger x = y;
 // BigInteger z = 123;

  BigInteger a, b;
  char o;
  cin >> a >> o >> b;
  switch(o){
      case '+': cout << a + b << "\n";break;
      case '-': cout << a - b << "\n";break;
      case '*': cout << a * b << "\n";break;
      case '/': cout << a / b << "\n";break;
  }
  //cout << a + b << "\n";
 // cout << BigInteger::BASE << "\n";
  return 0;
}
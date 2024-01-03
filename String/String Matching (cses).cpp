#include<bits/stdc++.h>
using namespace std;

const int  N = 1e6+9;
const int  p1 = 137, mod1 = 1e9+7, p2 = 277, mod2 = 1e9+7;
vector<pair<int, int>>pw(N),ipw(N);

 long long BinExp(long long a,long long n,long long mod)
 {
      long long res = 1;
      while(n)
      {                                  
          if(n%2) res =(res*a)%mod;
          a =(a*a)%mod;
          n /= 2;
      }
      return res%mod;
 }

void prec(){
   pw[0] = {1,1};
   ipw[0] = {1,1};
   int ip1 = (int) BinExp(p1,mod1-2,mod1);
   int ip2 = (int) BinExp(p2,mod2-2,mod2);
   //cout<<ip1<<" "<<ip2<<endl;
   for(int i=1;i<N;i++){
      pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
      pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
      ipw[i].first = 1LL * ipw[i-1].first* ip1 % mod1;
      ipw[i].second = 1LL * ipw[i-1].second* ip2 % mod2;
   }
}

pair<int,int>string_hash(string s){
   int n = s.size();
   pair<int,int>hs = {0,0};

   for(int i=0;i<n;i++){
      hs.first += (1LL * s[i] * pw[i].first) % mod1;
      hs.first%=mod1;
      hs.second += (1LL * s[i] * pw[i].second) % mod2;
      hs.second%=mod2;
   }

   return hs;
}

vector<pair<int,int>>pre(N);
void build(string s){
   int n = s.size();
   for(int i=0;i<n;i++){
      pre[i].first = 1LL * s[i] * pw[i].first % mod1;
      if(i) pre[i].first  = (pre[i-1].first + pre[i].first) % mod1;
      
      pre[i].second = 1LL * s[i] * pw[i].second % mod2;
      if(i) pre[i].second = (pre[i-1].second + pre[i].second) % mod2;
   }
}

pair<int,int> get_hash(int i, int j){
   pair<int,int> hs = {0,0};
   hs.first = pre[j].first;
   if(i) hs.first = (hs.first - pre[i-1].first + mod1) % mod1;
   hs.first = 1LL * hs.first * ipw[i].first % mod1;

   hs.second = pre[j].second;
   if(i) hs.second = (hs.second - pre[i-1].second + mod2) % mod2;
   hs.second = 1LL * hs.second * ipw[i].second % mod2;
   
   return hs;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  prec();
  string a,b;
  cin>>a>>b;
  build(a);
  pair<int,int> hs_b = string_hash(b);

  int n = a.size();
  int m = b.size();
  int ans = 0 ;
  for(int i=0;i+m-1<n;i++){
     if(get_hash(i,i+m-1) == hs_b) ans++;
  }

  cout<<ans<<endl;


}

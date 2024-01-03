#include<bits/stdc++.h>
using namespace std;

const int  N = 1e6+9;
const int  p1 = 137, mod1 = 1e9+7, p2 = 277, mod2 = 1e9+9;
vector<pair<int, int>>pw(N);

void prec(){
   pw[0] = {1,1};
   for(int i=1;i<N;i++){
      pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
      pw[i].second = 1LL *pw[i-1].second * p2 % mod2;
   }
}

pair<int,int>get_hash(string s){
   int n = s.size();
   pair<int,int>hs = {0,0};

   for(int i=0;i<n;i++){
      hs.first += 1LL * s[i] * pw[i].first % mod1;
      hs.second += 1LL * s[i] * pw[i].second % mod2;
   }

   return hs;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  prec();
  string a,b;
  cin>>a>>b;

  if(get_hash(a)==get_hash(b)) cout<<"YES\n";
  else cout<<"NO\n";
}

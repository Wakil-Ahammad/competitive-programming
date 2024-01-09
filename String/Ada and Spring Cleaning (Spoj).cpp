// https://www.spoj.com/problems/ADACLEAN/en/

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define f first
#define s second
#define in insert
#define pll pair<ll,ll>
#define pii pair<int,int>
#define er erase
#define pi 3.141592653589793238
#define MOD 1000000007
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)1000000000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const int N = 1e5+5, p1 = 137,p2 = 277, mod1 = 1e9+7, mod2 = 1e9+9;
pair<int,int>pw[N] , ipw[N];

 int BinExp(ll a,ll n,int mod)
 {
      int res = 1;
      while(n)
      {                                  
          if(n%2) res =( res*a)%mod;
          a =(a*a)%mod;
          n /= 2;
      }
      return res%mod;
 }

void prec(){
   pw[0] = {1,1};
   ipw[0] = {1,1};
   int ip1 = BinExp(p1,mod1-2,mod1);
   int ip2 = BinExp(p2,mod2-2,mod2);

   for(int i=1;i<N;i++){
      pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
      pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
      ipw[i].first = 1LL * ipw[i-1].first * ip1 % mod1;
      ipw[i].second = 1LL * ipw[i-1].second * ip2 % mod2;
   }
}

pair<int,int>pre[N];
void build(string s) {
   int n = s.size();
   for(int i=0;i<n;i++){
      pre[i].first = 1LL * s[i] * pw[i].first % mod1;
      if(i) pre[i].first = (pre[i-1].first + pre[i].first) % mod1;
      pre[i].second = 1LL * s[i] * pw[i].second % mod2;
      if(i) pre[i].second = (pre[i-1].second + pre[i].second) % mod2;
   }
}

pair<int,int> get_hash(int i, int j){
    pair<int,int> hs;
    hs.first = pre[j].first;
    if(i) hs.first = (hs.first - pre[i-1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;

    hs.second = pre[j].second;
    if(i) hs.second = (hs.second - pre[i-1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}

void solve()
{
   int n,k;
   string s;
   cin>>n>>k>>s;
   build(s);
   map<pair<int,int>,int> mp;

   for(int i = 0;i+k-1<n;i++){
      pair<int,int> hs = get_hash(i,i+k-1);
      mp[hs]++;
   }

   cout<<mp.size()<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  prec();
  int t;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

// https://atcoder.jp/contests/dp/tasks/dp_p?lang=en

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
#define mod 1000000007
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)1000000000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const ll N = 1e5+5;
vector<ll>g[N];
ll dp[N][2];
ll n;

void dfs(ll u, ll p){
   dp[u][0] = 1;
   dp[u][1] = 1;

   for(auto v: g[u]){
       if(v==p) continue;
       dfs(v,u);
       dp[u][0] = (dp[u][0]*(dp[v][0] + dp[v][1]) % mod) % mod;
       dp[u][1] = (dp[u][1] * dp[v][0])%mod;
   }
}

void solve()
{
   cin>>n;
   for(ll i=0;i<n-1;i++){
      ll x,y;
      cin>>x>>y;
      g[x].pb(y);
      g[y].pb(x);
   }
   
   dfs(1,-1);
   cout<<(dp[1][0] + dp[1][1]) % mod;

   
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t=1;
  //cin>>t;
  while(t--)
  {
     solve();
  }
    
}

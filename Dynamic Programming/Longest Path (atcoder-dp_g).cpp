// https://atcoder.jp/contests/dp/tasks/dp_g?lang=en

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

const ll N = 1e5+5;
ll dp[N];
vector<ll>g[N];

ll length(ll u) {
    if(dp[u] !=-1) return dp[u];
    ll ans = 0;
    for(auto v: g[u]){
        ans = max(ans,1+length(v));
    }

    return dp[u] = ans;
}

void solve()
{
  ll n,m;
  cin>>n>>m;
  memset(dp,-1, sizeof dp);
  for(ll i=0;i<m;i++){
     ll x,y;
     cin>>x>>y;
     g[x].pb(y);
  }

  ll ans = 0;

  for(ll i=1;i<=n;i++){
     ans = max(ans,length(i));
  }

  cout<<ans<<endl;

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

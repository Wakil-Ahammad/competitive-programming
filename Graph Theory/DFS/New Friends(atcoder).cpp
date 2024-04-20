// https://atcoder.jp/contests/abc350/tasks/abc350_d

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

const ll N = 2e5 + 5;
vector<ll> g[N];
ll vis[N];
ll n,m;
ll cnt = 0;
void dfs(ll u){
   cnt++;
   vis[u] = 1;

   for(auto v : g[u]){
      if(!vis[v]) dfs(v);
   }
}

void solve()
{
   cin>>n>>m;

   for(ll i=0;i<m;i++){
      ll x,y;
      cin>>x>>y;
      g[x].pb(y);
      g[y].pb(x);
   }

   ll ans = 0;

   for(ll i=1;i<=n;i++){
      cnt = 0;
      if(!vis[i]){
        dfs(i);
        ans += (cnt*(cnt-1)/2);
      }

   }

   cout<<ans-m<<endl;
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

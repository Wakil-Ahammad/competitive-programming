// https://codeforces.com/problemset/problem/862/B

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
vector<ll>g[N];
ll color[N];
ll vis[N];

void dfs(ll u){
    vis[u] = 1;
    for(auto v: g[u]){
        if(!vis[v]){
            color[v] = !color[u];
            dfs(v);
        }
    }
}


void solve()
{
   ll n;
   cin>>n;

   for(ll i=1;i<n;i++){
      ll u,v;
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
   }
   
   memset(color,0,sizeof color);
   memset(vis,0,sizeof vis);
   
   dfs(1);

   ll zero = 0, one = 0;
   
   for(ll i=1;i<=n;i++){
      if(color[i]) one++;
      else zero++;
   }

   ll ans = zero*one;
   ans-=(n-1);
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

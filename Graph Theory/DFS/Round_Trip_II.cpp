// https://cses.fi/problemset/task/1678

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)1000000000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const ll N = 2e5+5;
vector<ll>g[N];
ll col[N];
ll par[N];
ll n,m;
bool found = false;
ll last = -1,fast = -1;
void dfs(ll u){
   col[u] = 1;
   
   for(auto v : g[u]) {
      if(!col[v]){
         par[v] = u;
         dfs(v);
      }

      else if(!found && col[v]==1){
          last = u;
          fast = v;
          found = true;
      }
   }

   col[u] = 2;
}

void solve()
{
   cin>>n>>m;
   for(ll i=1;i<=m;i++){
      ll u,v;
      cin>>u>>v;
      g[u].pb(v);
   }
   
   memset(col,0,sizeof col);
   
   for(ll i=1;i<=n;i++) {
      if(!col[i] && !found){
         dfs(i);
      }

   }
   
   if(!found){
      cout<<"IMPOSSIBLE\n";
      return;
   }

   vector<ll>ans;
   ans.pb(fast);
   while(last != fast){
      ans.pb(last);
      last = par[last];
   }
   ans.pb(fast);

   
   reverse(all(ans));

   cout<<ans.size()<<endl;
   for(auto i: ans) cout<<i<<" ";
   cout<<endl;
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
// MultiSource BFS
// https://codeforces.com/problemset/problem/1272/E

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
#define INF (ll)10000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const ll N = 200005;
vector<ll>g[N];
ll ans[N], a[N],n;
void bfs(vector<ll>x, vector<ll>y){
   vector<ll>d(n+1,INF);
   queue<ll>q;

   for(ll i=0;i<x.size();i++) {
      q.push(x[i]);
      d[x[i]] = 0; 
   }

   while(!q.empty()){
      ll u = q.front();
      q.pop();

      for(auto v: g[u]){
         if(d[v] == INF){
            d[v] = d[u] +1;
            q.push(v);
         }
      }
   }

   for(auto i: y) ans[i] = d[i];
}


void solve()
{
   cin>>n;
   vector<ll>even,odd;
   for(ll i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]%2) odd.pb(i);
      else even.pb(i);
   }

   for(ll i=1;i<=n;i++){
      ll j = i+a[i];
      if(j<=n) g[j].pb(i);

      j = i-a[i];
      if(j>=1) g[j].pb(i);
   }
   
   for(ll i=1;i<=n;i++) ans[i] = INF;
   
   bfs(even,odd);
   bfs(odd,even);

   for(ll i=1;i<=n;i++){
      if(ans[i] == INF) ans[i] = -1;
      cout<<ans[i]<<" ";
   }

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

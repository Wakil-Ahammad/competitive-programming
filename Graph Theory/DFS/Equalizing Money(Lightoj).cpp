// https://lightoj.com/problem/equalizing-money

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

const ll N = 1005;
ll a[N];
vector<ll>g[N];
ll vis[N];
ll n,m;
ll person,taka;

void dfs(ll i){
    vis[i] = 1;
    person++;
    taka += a[i];
    for(auto v: g[i]){
       if(!vis[v]) dfs(v);
    }
}

void solve()
{
   cin>>n>>m;
   for(ll i=0;i<=n;i++){
      g[i].clear();
      vis[i] = 0;
   }

   for(ll i=0;i<n;i++) cin>>a[i];

   for(ll i=0;i<m;i++){
      ll x,y;
      cin>>x>>y;
      x--,y--;
      g[x].pb(y);
      g[y].pb(x);
   }
    set<ll>st;
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            person = 0, taka = 0;
            dfs(i);
            if(taka % person == 0){
               int amount = taka/person;
               st.insert(amount);
            }

            else{cout<<"No\n";return;}
        }
    }

    if(st.size() == 1) cout<<"Yes\n";
    else cout<<"No\n";
   
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k = 1;
  int t;
  cin>>t;
  while(t--)
  {
     cout<<"Case "<<k++<<": ";
     solve();
  }
    
}

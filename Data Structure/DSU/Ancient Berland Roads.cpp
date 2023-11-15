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


const int N = 5e5+5;
int par[N],sz[N];
ll population[N];
stack<int>st[N];
multiset<ll>ms;
void make_set(int n){
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
        population[i] = st[i].top();
        ms.insert(population[i]);
    }
}

int find_set(int u){
    if(par[u] == u) return u;
    return par[u] = find_set(par[u]);
}

void union_set(int u, int v){
    int a = find_set(u);
    int b = find_set(v);

    if(sz[a]<sz[b]) swap(a,b);
    
    if(a!=b){
        ms.erase(ms.find(population[a]));
        ms.erase(ms.find(population[b]));
        par[b] = a;
        sz[a] +=sz[b];
        population[a]+=population[b];
        ms.insert(population[a]);
    }
}


void solve()
{
   int n,m,q;
   cin>>n>>m>>q;

   for(int i=1;i<=n;i++){
      int p;
      cin>>p;
      st[i].push(p);
   }

   vector<pair<int,int>>edges;
   for(int i=1;i<=m;i++){
      int u,v;
      cin>>u>>v;
      edges.pb({u,v});
   }

   vector<pair<int,pair<int,int>>>queries;
   vector<int>destroyed(m+2);

   for(int i=1;i<=q;i++){
      char ch;
      cin>>ch;
      if(ch =='D'){
        int k;
        cin>>k;
        k--;
        destroyed[k] = 1;
        queries.pb({0,{k,-1}});
      }

      else {
         int a,x;
         cin>>a>>x;
         st[a].push(x);
         queries.pb({1,{a,x}});
      }
   }

   make_set(n);

   for(ll i=0;i<m;i++){
      if(!destroyed[i]){
         union_set(edges[i].first,edges[i].second);
      }
   }
   
   vector<ll>ans;
 
   for(ll i= queries.size()-1; i>=0;i--){
      ans.pb(*(--ms.end()));

      if(queries[i].first ==0){
         ll idx = queries[i].second.first;
         ll u = edges[idx].first;
         ll v = edges[idx].second;
         union_set(u,v);
      }

      else {
         ll a = queries[i].second.first;
         ll x = queries[i].second.second;

         ms.erase(ms.find(population[find_set(a)]));

         ll curr_p = st[a].top();
         st[a].pop();
         population[find_set(a)] -=curr_p;
         ll new_p = st[a].top();
         population[find_set(a)]+=new_p;
         ms.insert(population[find_set(a)]);
      }
   }

   reverse(all(ans));

   for(auto i: ans)cout<<i<<endl;
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

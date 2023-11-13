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

const int N = 1e5+5;
int par[N],sz[N];

void make_set(int n){
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
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
        par[b] = a;
        sz[a] +=sz[b];
    }
}

void solve() {
   int n,m;
   cin>>n>>m;
   make_set(n);

   vector<int>vis(m+2);
   vector<pair<int,int>>a;
   for(int i=1;i<=m;i++){
      int u,v;
      cin>>u>>v;
      a.push_back({u,v}); 
   }

   int q;
   cin>>q;
   vector<int>thread;
   for(int i=1;i<=q;i++){
      int x;
      cin>>x;
      --x;
      vis[x] =1;
      thread.pb(x);
   }
   
   cout<<endl;
   
   for(int i=0;i<a.size();i++){
      if(!vis[i]){
         union_set(a[i].first,a[i].second);
      }
   }

   set<int>st;

   for(int i=1;i<=n;i++){
      st.insert(find_set(i));
   }

   vector<int>ans;
   reverse(all(thread));

   //for(auto i:thread) cout<<i<<" ";cout<<endl;
   for(int i=0;i<thread.size();i++){
      ans.pb(st.size());
      int x = thread[i];
      st.erase(find_set(a[x].first));
      st.erase(find_set(a[x].second));
      union_set(a[x].first,a[x].second);
      st.insert(find_set(a[x].first));
   }

   reverse(all(ans));

   for(auto i:ans) cout<<i<<" ";cout<<endl;
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

//https://acm.timus.ru/problem.aspx?space=1&num=1671

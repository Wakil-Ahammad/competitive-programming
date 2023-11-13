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
ll par[N],sz[N];
ll cs = 1;
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

void solve()
{
   ll n,q;
   cin>>n>>q;
   map<ll,ll>mp;
   make_set(n);

   for(ll i=1;i<=n;i++){
      ll x;
      cin>>x;
      if(!mp[x]){mp[x] =i;}
      else {
         union_set(i,mp[x]);
      }
   }

   map<ll,ll>val,rep;

   for(auto it:mp){
      val[find_set(it.second)] = it.first;
      rep[it.first] = find_set(it.second);
   }

   cout<<"Case "<<cs++<<": \n"; 

   while(q--){
      ll type;
      cin>>type;

      if(type==2){
         ll ind;
         cin>>ind;
         cout<<val[find_set(ind)]<<endl;
      }

      else{
         ll x,y;
         cin>>x>>y;
         if(!rep[x]) continue;
         else if(!rep[y]){
            int r = rep[x];
            val[r] = y;
            rep[y] = r;
            rep.erase(x);
         }
         else{
            int r1 = rep[x];
            int r2 = rep[y];
            union_set(r1,r2);
            val[find_set(r1)] = y;
            rep[y] = find_set(r1);
            if(x!=y) rep.erase(x);
         }
      }
   }
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

// https://toph.co/p/unbelievable-array

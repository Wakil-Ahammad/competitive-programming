// https://codeforces.com/problemset/problem/580/C

#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define f first
#define s second
#define in insert
// count(s.begin(), s.end(), '0')
#define er erase
#define pi 3.141592653589793238
#define YES cout << "YES\n"
#define NO cout << "NO\n"
//#define end cout<<endl
#define bcntz __builtin_ctz 
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())
 
const int N = 100005;
ll n,m;
vector<ll>g[N];
ll a[N],r[N],vis[N];
ll cnt=0;
 
void dfs(ll vertex)
{
    vis[vertex]=1;
    bool leaf = true;
    for(auto i:g[vertex])
    {
        if(!vis[i])
        {
            leaf = false;
            if(a[i] == 1) r[i] = r[vertex]+1;
            if(r[i] > m) continue;;
            dfs(i);
        }
    }

    if(leaf) cnt++;
}
 
 
int main()
{
    
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
 
    for(ll i=0;i<n-1;i++)
    {
       ll u,v;
       cin>>u>>v;
       g[u].pb(v);
       g[v].pb(u);
    }
 
    if(a[1]==1)r[1]=1;
 
    dfs(1);
    cout<<cnt<<endl;
  
}

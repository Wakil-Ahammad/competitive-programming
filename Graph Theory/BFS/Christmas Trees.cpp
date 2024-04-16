// MultiSource BFS
// https://codeforces.com/contest/1283/problem/D 

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


void solve()
{
   ll n,m;
   cin>>n>>m;
   queue<ll>q;
   map<ll,ll>mp;
   for(ll i=0;i<n;i++){
      ll x;
      cin>>x;
      q.push(x);
      mp[x] = 0;
   }

   ll ans = 0;
   vector<ll>res;
   while(!q.empty() && m>0){
       ll v = q.front();
       q.pop();

       if(mp.find(v-1) == mp.end() && m>0){
           res.pb(v-1);
           mp[v-1] = mp[v]+1;
           ans += mp[v-1];
           q.push(v-1);
           m--;
       }

       if(mp.find(v+1) == mp.end() && m>0){
           res.pb(v+1);
           mp[v+1] = mp[v]+1;
           ans += mp[v+1];
           q.push(v+1);
           m--;
       }
   }

   cout<<ans<<endl;
   for(auto it: res) cout<<it<<" ";
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

//https://cses.fi/problemset/task/2168/

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
 
struct range{
   ll l,r,pos;
};
 
bool cmp(const range a, const range b){
    if(a.l < b.l) return true;
    if(a.l == b.l){
        return a.r > b.r;
    }
 
    return false;
}
 
void solve()
{
   ll n;
   cin>>n;
   vector<range> v(n);
   vector<ll> contains(n), contained(n);
 
   for(ll i=0;i<n;i++){
      cin>>v[i].l>> v[i].r;
      v[i].pos = i;
   }
 
   sort(v.begin(),v.end(),cmp);
   
   ll mxr = 0;
 
   for(ll i=0;i<n;i++){
      if(v[i].r <= mxr){
        contained[v[i].pos] = 1;
      }
 
      mxr = max(v[i].r,mxr);
   }
 
   ll mnr = 2e9 + 5;
   
   for(ll i=n-1;i>=0;i--){
      if(v[i].r >= mnr){
         contains[v[i].pos] = 1;
      }
 
      mnr = min(v[i].r,mnr);
   }
 
   for(auto i: contains) cout<<i<<" ";cout<<endl;
   for(auto i: contained) cout<<i<<" ";cout<<endl;
 
 
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

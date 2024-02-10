// https://codeforces.com/contest/1918/problem/C

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
#define chkbit(n,i) (n & (1LL<<i))
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())


void solve()
{
   ll a,b,r;
   cin>>a>>b>>r;
   if(a<b) swap(a,b);
   ll f= 0;
   ll x = 0;

   for(ll i=60;i>=0;i--){
      if(chkbit(a,i) == chkbit(b,i)) continue;

      if(chkbit(a,i)){
        
        if(f==0) {f=1;continue;}
        
        else {
          ll v = x;
          v|=(1LL<<i);
          if(v<=r)  x|=(1LL<<i);
        }
      }

   }

   cout<<(a^x) - (b^x)<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t=1;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

// https://lightoj.com/problem/neighbor-house 

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

const ll N = 22;
ll n,r[N],g[N],b[N];
ll dp[N][3];

ll f(ll i,ll prev){
   if(i==n) return 0;
   if(dp[i][prev] != -1) return dp[i][prev];
   ll ans = INF;
   for(ll j = 0;j<3;j++){
      if(j!=prev){
        if(j==0) ans = min(ans,r[i]+f(i+1,0));
        else if(j==1) ans = min(ans,g[i]+f(i+1,1));
        else if(j==2) ans = min(ans,b[i]+f(i+1,2));
      }
   }

   return dp[i][prev] = ans;

}


void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n;
   for(ll i=0;i<n;i++) cin>>r[i]>>g[i]>>b[i];
   cout<<f(0,3)<<endl;
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

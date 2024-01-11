// https://atcoder.jp/contests/dp/tasks/dp_e?lang=en

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
#define INF (ll)1e18
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const int N = 105;
ll dp[N][N*1000];
ll w[N],v[N];
ll n,capacity;

ll f(ll i, ll rem){
    if(i==n){
        if(rem==0) return 0;
        else return INF;
    }
    if(dp[i][rem] !=-1) return dp[i][rem];

    ll ans = INF;

    ans = min(ans,f(i+1,rem));
    ans = min(ans, w[i] + f(i+1,rem-v[i]));

    return dp[i][rem] = ans;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n>>capacity;
   for(ll i=0;i<n;i++){cin>>w[i]>>v[i];}
   ll ans = -1;
   for(ll total_val=1;total_val<=n*1000;total_val++){
      ll val = f(0,total_val);
      if(val<=capacity){
         ans = max(ans,total_val);
      }
   }

   cout<<ans<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t=1;
 // cin>>t;
  while(t--)
  {
     solve();
  }
    
}

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

const ll N = 100005;
ll dp[105][N];
ll weight[N],val[N];
ll n;

ll f(ll i,ll rem){
    if(i==n) return 0;
    if(dp[i][rem] !=-1) return dp[i][rem];
    ll res = -INF;
    res = max(res,f(i+1,rem));
    if(rem>=weight[i]) res = max(res,val[i]+f(i+1,rem-weight[i]));

    return dp[i][rem] = res;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   ll W;
   cin>>n>>W;
   for(ll i=0;i<n;i++) cin>>weight[i]>>val[i];
  
   cout<<f(0,W);

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

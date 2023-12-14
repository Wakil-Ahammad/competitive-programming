// https://atcoder.jp/contests/abc261/tasks/abc261_d?lang=en

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

const ll N = 5005;
ll dp[N][N];
ll a[N];
map<ll,ll>mp;
ll n,m;

ll f(ll i, ll cnt){
    if(i==n) return 0;
    if(dp[i][cnt] !=-1) return dp[i][cnt];
    ll res = -INF;
    res = max(res,a[i]+mp[cnt+1]+f(i+1,cnt+1));
    res = max(res,mp[0]+f(i+1,0));
    return dp[i][cnt] = res;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n>>m;
   for(ll i=0;i<n;i++) cin>>a[i];
   for(ll i=0;i<m;i++){
      ll x,y;
      cin>>x>>y;
      mp[x] = y;
   }
   cout<<f(0,0)<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t = 1;
  //cin>>t;
  while(t--)
  {
     solve();
  }
    
}

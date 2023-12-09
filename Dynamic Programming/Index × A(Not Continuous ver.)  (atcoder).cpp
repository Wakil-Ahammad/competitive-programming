// https://atcoder.jp/contests/abc267/tasks/abc267_d

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

const ll N = 2005;
ll a[N];
ll dp[N][N];
ll n,m;
ll f(ll i, ll k){
    if(i==n){
        if(k==m) return 0;
        else return -INF;
    }

    if(k>m) return -INF;

    if(dp[i][k]) return dp[i][k];
    ll res = -INF;
    res = max(res,f(i+1,k));
    res = max(res,((k+1)*a[i])+f(i+1,k+1));
    
    return dp[i][k] = res;

}

void solve()
{
   memset(dp,0,sizeof dp);
   cin>>n>>m;
   for(ll i=0;i<n;i++) cin>>a[i];
   cout<<f(0,0)<<endl;
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

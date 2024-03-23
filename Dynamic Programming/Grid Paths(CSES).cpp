// https://cses.fi/problemset/task/1638/

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
#define mod 1000000007
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)1000000000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const ll N = 1005;
ll n;
char grid[N][N];
ll dp[N][N];

ll f(ll i,ll j){
    if(i==n || j==n || grid[i][j] == '*') return 0;
    if(i==n-1 && j== n-1) return 1;
    if(dp[i][j] !=-1) return dp[i][j];
    
    ll ans = 0;
    ans += f(i+1,j);
    ans += f(i,j+1);
    ans %= mod;
    return dp[i][j] = ans;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n;
   for(ll i=0;i<n;i++) cin>>grid[i];

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

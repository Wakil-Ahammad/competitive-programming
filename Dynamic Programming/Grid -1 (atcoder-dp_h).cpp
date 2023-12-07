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
ll dp[N][N];
char a[N][N];
ll n,m;

ll f(ll row, ll col){
    if(row == n and col == m) return 1;
    if(row>n or col>m or a[row][col] == '#') return 0;
    if(dp[row][col] !=-1) return dp[row][col];
    ll res = 0;
    res = (res +f(row,col+1))%mod;
    res = (res +f(row+1,col))%mod;

    return dp[row][col] = res;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   
   cin>>n>>m;
   for(ll i=1;i<=n;i++){
      for(ll j=1;j<=m;j++){
          cin>>a[i][j];
      }
   }

   cout<<f(1,1)<<endl;
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

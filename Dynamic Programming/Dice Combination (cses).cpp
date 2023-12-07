// https://cses.fi/problemset/task/1633

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

const ll N = 1e6+5;
ll dp[N];
ll n;

ll f(ll x){
    if(x==n) return 1;
    if(x>n) return 0;

    if(dp[x]!=-1) return dp[x];

    ll res = 0;
    for(ll i=1;i<=6;i++){
        res=( res+f(x+i))%mod;
    }

    return dp[x] = res;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n;
   cout<<f(0)<<endl;
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

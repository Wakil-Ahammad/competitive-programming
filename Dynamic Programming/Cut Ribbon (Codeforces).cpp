// https://codeforces.com/problemset/problem/189/A

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

const ll N = 4005;
ll dp[N];
ll n,a,b,c;

ll f(ll n){
    if(n==0) return 0;
    if(n<0) return -INF;
    
    if(dp[n] !=-1) return dp[n];

    ll res = -INF;
    res = max(res,1+f(n-a));
    res = max(res,1+f(n-b));
    res = max(res,1+f(n-c));

    return dp[n] = res;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n>>a>>b>>c;

   cout<<f(n)<<endl;
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

//https://codeforces.com/contest/1881/problem/E

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

const ll N = 2e5+5;
ll dp[N];
ll a[N];
ll n;

ll f(ll i){
   if(i==n) return 0;
   if(i>n) return INF;
   if(dp[i] !=-1) return dp[i];
   ll ans = INF;
   ans = min(ans,1 + f(i+1));
   ans = min(ans,f(i+a[i]+1));

   return dp[i] = ans;
}

void solve()
{
   cin>>n;
   for(ll i=0;i<n;i++) cin>>a[i];
   memset(dp,-1,sizeof dp);
   cout<<f(0)<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

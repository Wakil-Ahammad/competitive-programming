// https://lightoj.com/problem/neighbor-house-ii

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

const ll N = 1002;
ll a[N];
ll n;
ll dp[N][2][2];

ll f(ll i, ll prev, ll frst){
   
   if(i==n) return 0;
   
   if(dp[i][prev][frst] != -1) return dp[i][prev][frst];
   
   ll ans = -INF;
   if((prev==1) || (i==n-1 && frst)) {
       ans = max(ans,f(i+1,0,frst));
   }

   else {
     ans = max(ans,f(i+1,0,frst));
     if(i==0) ans = max(ans,a[i]+f(i+1,1,frst^1));
     else ans = max(ans,a[i]+f(i+1,1,frst));
   }

   return dp[i][prev][frst] = ans;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n;
   for(ll i=0;i<n;i++) cin>>a[i];
   cout<<f(0,0,0)<<endl;
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

// https://lightoj.com/problem/coin-change-i

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
#define mod 100000007
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)1000000000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const int N = 52, K = 1005;
int n,k;
int a[N],c[N];
int dp[N][K];

int f(int i, int cur){

   if(cur>k) return 0;
   if(i==n){
     if(cur==k) return 1;
     return 0;
   }

   if(dp[i][cur] != -1) return dp[i][cur];

   int ans = 0;

   for(int cnt = 0;cnt<=c[i];cnt++){
      ans += f(i+1, cur + (cnt*a[i]));
      ans %= mod;
   }

   return dp[i][cur] = ans;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n>>k;

   for(int i=0; i<n;i++) cin>>a[i];
   for(int i=0; i<n;i++) cin>>c[i];

   cout<<f(0,0)<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p=1;
  int t;
  cin>>t;
  while(t--)
  {
     cout<<"Case "<<p++<<": ";
     solve();
  }
    
}

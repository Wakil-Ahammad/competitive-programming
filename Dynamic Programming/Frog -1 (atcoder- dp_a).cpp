// https://atcoder.jp/contests/dp/tasks/dp_a?lang=en

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
#define INF (ll)1000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const int N = 1e5+5;
int a[N];
int dp[N];
int n;

int f(int i) {  
   if(i==n) return 0;
   if(i>n) return INF;
   
   if(dp[i] !=-1) return dp[i];

   int res = INF;
  
   res = min(res,abs(a[i]-a[i+1])+f(i+1));
   res = min(res,abs(a[i]-a[i+2])+f(i+2));

   return dp[i] = res;
}


void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   cout<<f(1)<<endl;
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

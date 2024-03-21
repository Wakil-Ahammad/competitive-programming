// https://cses.fi/problemset/task/1639/

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

const ll N = 5002;
string s,t;
ll n,m;

ll dp[N][N];

ll f(ll i,ll j){
   if(i==n){
      if(j==m) return 0;
      return m-j;
   }
  
   if(j==m){
     if(i==n) return 0;
     return n-i;
   }

   if(dp[i][j] != -1) return dp[i][j]; 

   ll ans = INF;

   if(s[i]== t[j]) ans = min(ans,f(i+1,j+1));

   ans = min(ans,1+f(i,j+1));
   ans = min(ans,1+f(i+1,j));
   ans = min(ans,1+f(i+1,j+1));

   return dp[i][j] = ans;
}

void solve()
{
   memset(dp,-1, sizeof dp);
   cin>>s>>t;
   n = s.size();
   m = t.size();

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

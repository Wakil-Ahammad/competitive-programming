// https://codeforces.com/problemset/problem/1513/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define CC(x) cout << "Case " << ++x << ":";
#define nn "\n"
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
#define mod 1000000007
#define N 200005

int dp[10][N];

int  f(int d,int m)
{
   if(m==0) return 1;
   
   int res = 0;
   
   if(dp[d][m] !=-1) return dp[d][m];

   if(d<9) res = f(d+1,m-1);

   else res = f(1,m-1) + f(0,m-1);

   return dp[d][m] = res%mod;
}

int main()
{
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   memset(dp,-1,sizeof dp);
   int t;
   cin>>t;

   while(t--)
   {

      string s;
      cin>>s;
      int m;
      cin>>m;

      int ans = 0;

      for(int i=0;i<s.size();i++)
      {
         int d = s[i]-'0';
         ans=(ans+f(d,m))%mod;
      }

      cout<<ans<<endl;
   }
 
}


// https://cses.fi/problemset/task/1744/

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
#define N 100005
 
ll dp[505][505];
 
ll f(ll h,ll w)
{
   if(h==w) return 0;
 
   if(dp[h][w] != -1) return dp[h][w];
 
   ll res = INF;
 
   for(ll i=1;i<h;i++)
   {
      res = min(res,1+f(i,w)+f(h-i,w));
   }
 
   for(ll i=1;i<w;i++)
   {
      res = min(res, 1+f(h,i)+f(h,w-i));
   }
 
   return dp[h][w] = res;
}
 
 
int main()
{
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll t=1;
    //cin>>t;
 
    while(t--)
    {
       memset(dp,-1,sizeof dp);
 
       ll h,w;
       cin>>h>>w;
       cout<<f(h,w)<<endl;
    }
}

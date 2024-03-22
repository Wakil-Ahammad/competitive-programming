// https://lightoj.com/problem/divisible-group-sums

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

const ll N = 202, D = 22,M = 12;
ll a[N];
ll n,m,d;
ll dp[N][D][M];

ll f(ll i, ll cur, ll rem){

    if(rem<0) return 0;

    if(i==n){
       if(rem == 0 && cur == 0) return 1;
       return 0;
    }

    if(dp[i][cur][rem] != -1) return dp[i][cur][rem];

    ll ans = 0;
    ans+=f(i+1,cur,rem);
    ans+=f(i+1,(cur+ (a[i]%d+d)%d)%d,rem-1);
    
    return dp[i][cur][rem] = ans;
}

void solve()
{
   ll q;
   cin>>n>>q;
   for(ll i=0;i<n;i++) cin>>a[i];
   
   while(q--){
     memset(dp,-1,sizeof dp);
     cin>>d>>m;
     cout<<f(0,0,m)<<endl;
   }
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k =1;
  int t;
  cin>>t;
  while(t--)
  {
     cout<<"Case "<<k++<<": \n";
     solve();
  }
    
}

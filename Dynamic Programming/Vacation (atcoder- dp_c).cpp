// https://atcoder.jp/contests/dp/tasks/dp_c?lang=en

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

const ll N = 1e5+5;
ll a[N][3];
ll n;
ll dp[N][3];

ll f(ll day, ll prev){
    if(day>n) return 0;
    
    if(dp[day][prev] !=-1) return dp[day][prev];
    ll mx = 0;
    for(ll i=0;i<3;i++){
        if(day==1 or i!=prev){
            mx = max(mx,a[day][i]+f(day+1,i));
        }
    }

    return dp[day][prev] = mx;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n;
   for(ll i=1;i<=n;i++){
      cin>>a[i][0]>>a[i][1]>>a[i][2];
   }

   cout<<f(1,0)<<endl;
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

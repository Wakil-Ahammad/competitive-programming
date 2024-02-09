// https://atcoder.jp/contests/dp/tasks/dp_i

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

const ll N = 3005;
double dp[N][N];
bool vis[N][N];
double p[N];
ll n;

double f(ll i,ll head, ll tail){
    if(i==n+1){
        if(head>tail) return 1;
        else return 0;
    }

    if(vis[i][head]) return dp[i][head];
    vis[i][head] = true;

    double ans = 0;

    ans+= (p[i] * f(i+1,head+1,tail));
    ans+= (1-p[i]) * f(i+1, head, tail+1);
    
    return dp[i][head] = ans;
}


void solve()
{
   cin>>n;
   for(ll i=1;i<=n;i++) cin>>p[i];
   cout<<fixed<<setprecision(10)<<f(1,0,0)<<endl;
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

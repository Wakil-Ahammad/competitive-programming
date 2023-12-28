// https://atcoder.jp/contests/abc271/tasks/abc271_d

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

ll dp[105][10005];
ll a[105],b[105];
ll chk[105][10005];
ll n,k;

ll f(ll i, ll sum){
    if(i == n){
       if(sum==k) return 1;
       else return 0;
    }

    if(sum>k) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    ll res = 0;
    ll t1 = f(i+1,sum+a[i]);
    ll t2 = f(i+1,sum+b[i]);
    
    if(t1==1) chk[i][sum] = 1;
    if(t2==1) chk[i][sum] = 2;

    res = t1|t2;
    
    return dp[i][sum] = res;

}

void way(ll i, ll sum){
    if(i==n) return;
    if(sum>k) return;

    if(chk[i][sum] == 1){
        cout<<"H";
        way(i+1,sum+a[i]);
    }

    else{
        cout<<"T";
        way(i+1,sum+b[i]);
    }
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>n>>k;
   for(ll i=0;i<n;i++){
     cin>>a[i]>>b[i];
   }

   if(f(0,0)){
      cout<<"Yes\n";
      way(0,0);
   }

   else cout<<"No\n";
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

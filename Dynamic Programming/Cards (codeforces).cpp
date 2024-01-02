// https://codeforces.com/problemset/problem/626/B

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

ll dp[205][205][205];

ll f(ll b, ll g, ll r){
    if(b+g+r==1){
        if(b==1) return 1;
        else if(g==1) return 2;
        else return 4;
    }

    if(dp[b][g][r] !=-1) return dp[b][g][r];

    ll res = 0;

    if(b>0 and g>0) res |=f(b-1,g-1,r+1);
    if(b>0 and r>0) res |=f(b-1,g+1,r-1);
    if(g>0 and r>0) res |=f(b+1,g-1,r-1);
    if(b>=2)  res |=f(b-1,g,r);
    if(g>=2)  res |=f(b,g-1,r);
    if(r>=2)  res |=f(b,g,r-1);

    return dp[b][g][r] = res;
}

void solve()
{
   ll n;
   cin>>n;
   string s;
   cin>>s;

   ll r = 0,b=0,g = 0;

   for(ll i=0;i<n;i++){
      if(s[i]=='R')r++;
      else if(s[i]=='B')b++;
      else g++;
   }

   memset(dp,-1,sizeof dp);

   ll ans = f(b,g,r);
    
   if(ans==1) cout<<"B\n";
   else if(ans==2) cout<<"G\n";
   else if(ans==3) cout<<"BG\n";
   else if(ans==4) cout<<"R\n";
   else if(ans==5) cout<<"BR\n";
   else if(ans==6) cout<<"GR\n";
   else cout<<"BGR\n";

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

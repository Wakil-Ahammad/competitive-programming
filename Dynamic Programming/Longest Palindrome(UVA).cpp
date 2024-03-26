// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2092

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

const ll N = 1002;
string s;
ll n;
ll dp[N][N];

ll f(ll l, ll r){

   if(l>r) return 0;
   if(l==r) return 1;

   if(dp[l][r] !=-1) return dp[l][r];

   ll ans = -INF;
   
   if(s[l] == s[r]){
      ans = max(ans,2+f(l+1,r-1));
   }

   else{
      ll tmp1 = f(l+1,r);
      ll tmp2 = f(l,r-1);
      ll tmp = max(tmp1,tmp2);
      ans = max(ans,tmp);
   }
   return dp[l][r] = ans;
}

void solve()
{
   memset(dp,-1,sizeof dp);
   getline(cin,s);
   n = s.size();
   cout<<f(0,n-1)<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin>>t;
  cin.ignore();
  while(t--)
  {
     solve();
  }
    
}

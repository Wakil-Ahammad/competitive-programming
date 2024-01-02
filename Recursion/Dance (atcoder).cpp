// https://atcoder.jp/contests/abc236/tasks/abc236_d?lang=en

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
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

ll a[17][17];
ll ans = 0;

void f(string s,ll xr){
   ll first = -1;
   ll n = s.size();
   for(ll i=0;i<n;i++){
      if(s[i]=='0'){
         first = i;
         break;
      }
   }

   if(first==-1){
      ans = max(ans,xr);
      return;
   }

   for(ll i=first+1;i<n;i++){
      if(s[i]=='0'){
         string t = s;
         t[i] = '1';
         t[first]='1';
         f(t,xr^a[first][i]);
      }
   }
}

void solve()
{
   ll n;
   cin>>n;

   for(ll i=0;i<2*n-1;i++){
      for(ll j=i+1;j<2*n;j++){
         cin>>a[i][j];
      }
   }

   string s="";
   for(ll i=0;i<2*n;i++) s+='0';

   f(s,0);

   cout<<ans<<endl;

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

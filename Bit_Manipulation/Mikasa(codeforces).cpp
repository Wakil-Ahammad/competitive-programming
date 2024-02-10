//  https://codeforces.com/contest/1554/problem/C

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
#define chkbit(n,i) (n &(1<<i))
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())


void solve()
{
   int n,m;
   cin>>n>>m;

   m = m+1;
   int k = 0;
   for(int i=31;i>=0;i--){
      if(chkbit(n,i) == chkbit(m,i)) continue;
      if(chkbit(n,i) && !chkbit(m,i)) break;
      if(!chkbit(n,i) && chkbit(m,i)) k|=(1<<i);
   }

   cout<<k<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t=1;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

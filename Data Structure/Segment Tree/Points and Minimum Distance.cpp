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


void solve()
{
   ll n;
   cin>>n;
   n = 2*n;
   ll a[n];
   ll b[n];
   for(ll i=0;i<n;i++){cin>>a[i]; b[i] = a[i];}

   sort(a,a+n);
   sort(b,b+n);
   reverse(b,b+n);
   ll cost1=0;
   ll cost2 = 0;
   
   for(ll i=1;i<n/2;i++)
   {
      cost1+=(a[i]-a[i-1]);
      cost2+=(b[i-1]-b[i]);
   }
  
   //cout<<a[n-1]<<endl;

   cout<<cost1+cost2<<endl;

   for(ll i=0,j=n-1;i<j;i++,j--)
   {
      cout<<a[i]<<" "<<a[j]<<endl;
   }
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

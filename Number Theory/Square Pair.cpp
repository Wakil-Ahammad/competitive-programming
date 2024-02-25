// https://atcoder.jp/contests/abc342/tasks/abc342_d

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

const ll N = 2e5+9;
vector<ll>lp(N);

void calc(){
    iota(all(lp),0);
    
    for(ll i=2;i<N;i++){
        if(lp[i]==i){
            for(ll j=i;j<N;j+=i){
                lp[j] = min(lp[j],i);
            }
        }
    }
}

ll square_free(ll n){
    ll val = 1;

    while(n>1){
        ll pf = lp[n];
        ll cnt = 0;
        while(n%pf == 0){
            n/=pf;
            cnt++;
        }

        if(cnt%2) val*=pf;
    }

    return val;
}

void solve()
{
   ll n;
   cin>>n;
   map<ll,ll>mp;
   ll zero = 0;
   for(ll i=0;i<n;i++){
      ll x;
      cin>>x;
      if(x==0){
         zero++;
         continue;
      }
      
      mp[square_free(x)]++;
   }

   ll ans = 0;
   ans+= zero*(n-zero) + (zero*(zero-1)/2);
   for(auto i:mp){
      ans +=(i.second*(i.second-1)/2);
   }

   cout<<ans<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  calc();
  int t=1;
  while(t--)
  {
     solve();
  }
    
}

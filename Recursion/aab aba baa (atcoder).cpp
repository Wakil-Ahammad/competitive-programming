// https://atcoder.jp/contests/abc202/tasks/abc202_d?lang=en

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

string s = "";

ll count_string(ll n,ll m){
    ll cnt = 1;
    n = n+m;
    ll r = m;

    for(ll i=0;i<r;i++){
        cnt*=(n-i);
        cnt/=(i+1);
    }

    return cnt;
}

void find(ll cnt_a,ll cnt_b, ll k){
    if(cnt_a==0 && cnt_b==0) return;

    ll lft = (cnt_a==0)? 0 : count_string(cnt_a-1,cnt_b);
    ll rgt = (cnt_b==0)? 0 : count_string(cnt_a,cnt_b-1);

    if(lft>=k){
        s+='a';
        find(cnt_a-1,cnt_b,k);
    }

    else{
        s+='b';
        find(cnt_a,cnt_b-1,k-lft);
    }
}

void solve()
{
   ll a,b,k;
   cin>>a>>b>>k;

   find(a,b,k);
   cout<<s<<endl;
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

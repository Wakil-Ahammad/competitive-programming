// https://lightoj.com/problem/an-easy-lcs

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

const ll N = 105;
string a,b;
bool vis[N][N];
string dp[N][N];

string f(ll i,ll j){
    if(i==a.size() or j==b.size()) return "";
    if(vis[i][j]) return dp[i][j];
    string ans = "";
    if(a[i] == b[j]){
        ans = string(1,a[i]) + f(i+1,j+1);
    }

    else{
        string x = f(i+1,j);
        string y = f(i,j+1);

        if(x.size()==y.size()) ans+= min(x,y);
        else if(x.size() > y.size()) ans+=x;
        else ans+=y;
    }

    vis[i][j] = true;
    return dp[i][j] = ans;
    

}

void solve()
{
   memset(vis,false,sizeof vis);
   cin>>a>>b;
   string ans = f(0,0);
   if(ans.empty()) cout<<":(\n";
   else cout<<ans<<endl;
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k = 1;
  int t;
  cin>>t;
  while(t--)
  {
     cout<<"Case "<<k++<<": ";
     solve();
  }
    
}

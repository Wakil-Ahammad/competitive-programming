// https://atcoder.jp/contests/dp/tasks/dp_f

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

string s,t;
ll dp[3005][3005];
ll mark[3005][3005];

ll f(int i,int j){
    if(i==s.size() || j == t.size()) return 0;
   
    if(dp[i][j] !=-1) return dp[i][j];

    ll res = 0;
    if(s[i]==t[j]){
        res = 1+f(i+1,j+1);
        mark[i][j]=1;
    }

    else{
       ll tmp1 = f(i,j+1);
       ll tmp2 = f(i+1,j);
       if(tmp1>tmp2) mark[i][j]=2;
       else mark[i][j] = 3;
       res = max(tmp1,tmp2);
    }

    return dp[i][j] = res;

}

void print_way(int i,int j){
    if(i==s.size() || j == t.size()) return;

    if(mark[i][j]==1){
        cout<<s[i];
        print_way(i+1,j+1);
    }

    else if(mark[i][j]==2){
        print_way(i,j+1);
    }

    else{
       print_way(i+1,j);
    }
}

void solve()
{
   memset(dp,-1,sizeof dp);
   cin>>s>>t;
   f(0,0);
   print_way(0,0);

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

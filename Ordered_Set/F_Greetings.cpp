// https://codeforces.com/problemset/problem/1915/F

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define f first
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mod 1000000007
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)10000000000000
#define all(x) x.begin(),x.end()
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



void solve()
{
   ll n;
   cin>>n;

   vector<pair<ll,ll>>a(n);

   for(ll i=0;i<n;i++){
     cin>>a[i].first>>a[i].second;
   }

   sort(all(a));

   o_set<ll> st;
   
   ll ans = 0;
   for(ll i=n-1;i>=0;i--){
      st.insert(a[i].second);
      ans += st.order_of_key(a[i].second);
   }
   
   cout<<ans<<endl;

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
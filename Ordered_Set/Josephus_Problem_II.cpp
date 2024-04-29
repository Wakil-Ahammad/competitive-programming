// https://cses.fi/problemset/task/2163/

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
   int n,k;
   cin>>n>>k;
 
   o_set<int>st;
 
   for(int i=1;i<=n;i++){
      st.insert(i);
   }
 
   ll pos = k%n;
 
   while(!st.empty()){
      auto it = st.find_by_order(pos);
      cout<<*(it)<<" ";
      st.erase(it);
 
      if(!st.empty()){
         pos = (pos+k) % st.size();
      }
   }
 
   cout<<endl;
}
 
int main()
{
   // #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
   // #endif
   ios::sync_with_stdio(false);
   cin.tie(0);
 
  int t=1;
  //cin>>t;
  while(t--)
  {
     solve();
  }
    
}
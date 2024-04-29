// https://cses.fi/problemset/task/2169

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


struct range{
   ll l,r,pos;
};

bool cmp(const range a, const range b){
    if(a.l < b.l) return true;
    if(a.l == b.l) return a.r > b.r;
    return false;
}

void solve()
{
   ll n;
   cin>>n;
   vector<range>v(n);
   
   for(ll i=0;i<n;i++){
      cin>>v[i].l>>v[i].r;
      v[i].pos = i;
   }

   sort(v.begin(),v.end(),cmp);
   
   o_set<pair<ll,ll>>st;
   ll contained[n],contain[n];
   
   for(ll i=0;i<n;i++){
      st.insert({v[i].r, i * (-1)});
      ll ind = st.order_of_key({v[i].r, i* (-1)});
      contained[v[i].pos] = st.size() - ind - 1;
   }
   
   st.clear();
   for(ll i=n-1;i>=0;i--){
      st.insert({v[i].r, i * (-1)});
      contain[v[i].pos] = st.order_of_key({v[i].r, i * (-1)});
   }

  for(auto i: contain) cout<<i<<" ";cout<<endl;
  for(auto i: contained) cout<<i<<" ";cout<<endl;
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
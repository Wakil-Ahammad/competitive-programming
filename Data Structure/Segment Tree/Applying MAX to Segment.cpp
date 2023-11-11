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
#define inf (ll)10000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

struct node{
    ll prop,val;
};

const ll N = 1e5+9;
ll a[N];
node t[N*4];
ll val = 0;
void build(ll node,ll b,ll e){
    if(b==e){
        t[node].val = a[b];
        //t[node].prop =0;
        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*node,r = 2*node+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[node].val = max(t[l].val,t[r].val);
    //t[node].prop = 0;
}

void update(ll node,ll b,ll e,ll i,ll j,ll x) {
    if(b>j or e<i) return;
    if(b>=i and e<=j) {
        t[node].val = max(t[node].val,x);
        t[node].prop = max(t[node].prop,x);
        return;
    }

    ll mid  = (b+e)/2;
    ll l = 2*node, r = 2*node+1;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);
    t[node].val = max({t[l].val,t[r].val,t[node].prop});
}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry) {
    if(b>j or e<i) return 0;
    if(b>=i and e<=j){
        return max(t[node].val,carry);
    }
    ll mid = (b+e)/2;
    ll l = 2*node, r = 2*node +1;
    ll t1 = query(l,b,mid,i,j, max(carry,t[node].prop));
    ll t2 = query(r,mid+1,e,i,j, max(carry,t[node].prop));
    return max(t1,t2);
}

void solve()
{
    ll n,q;
    cin>>n>>q;
    //for(ll i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(ll i=1;i<=q;i++){
      ll type;
      cin>>type;
      if(type ==1){
         ll l, r, v;
         cin>>l>>r>>v;
         update(1,1,n,l+1,r,v);
      }

      else{
        ll l,r;
        cin>>l;
        cout<<query(1,1,n,l+1,l+1,0)<<endl;
      }
   }
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

// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B

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

const ll N = 1e5+5;
struct node{
    int occ[3];
};

ll cs=1;

ll a[N];

node t[N*4];
ll lazy[N*4];

void push(ll n,ll b,ll e){

    if(lazy[n] ==0) return;

    node cur = t[n];

    for(ll i=0;i<3;i++){
        t[n].occ[(i+lazy[n])%3] = cur.occ[i];
    }

    if(b!=e){
        ll mid = (b+e)/2;
        ll l = 2*n, r = 2*n+1;
        lazy[l] = (lazy[l]+lazy[n])%3;
        lazy[r] = (lazy[r]+lazy[n])%3;
    }

    lazy[n] =0;
}

node merge(node l, node r){
    node ans;
    for(ll i=0;i<3;i++){
        ans.occ[i] = l.occ[i] + r.occ[i];
    }
    return ans;
}

void build(ll n,ll b,ll e){
    lazy[n] = 0;
    if(b==e){
        t[n].occ[0] =1;
        t[n].occ[1] =0;
        t[n].occ[2] =0;
        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*n, r= 2*n+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n] = merge(t[l],t[r]);
}

void update(ll n,ll b, ll e, ll i, ll j, ll x){
    push(n,b,e);
    if(b>j or e<i) return;
    if(b>=i and e<=j){
        lazy[n] = x;
        push(n,b,e);
        return;
    }

      ll mid = (b+e)/2;
      ll l = 2*n, r= 2*n+1;

      update(l,b,mid,i,j,x);
      update(r,mid+1,e,i,j,x);
      
      t[n] = merge(t[l],t[r]);
}

ll query(ll n, ll b, ll e, ll i, ll j){
    push(n,b,e);
    if(b>j or e<i) return 0;
    if(b>=i and e<=j){
        return t[n].occ[0];
    }
    
    
    ll mid = (b+e)/2;
    ll l = 2*n, r= 2*n+1;

    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);

}

void solve()
{

   ll n,q;
   cin>>n>>q;
   build(1,1,n);
   
   cout<<"Case "<<cs++<<": \n";
   while(q--){
      ll type;
      cin>>type;
      
      if(type == 0){
         ll l,r;
         cin>>l>>r;
         update(1,1,n,l+1,r+1,1);
      }

      else {
         ll l,r;
         cin>>l>>r;
         cout<<query(1,1,n,l+1,r+1)<<endl;
      }
   }
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

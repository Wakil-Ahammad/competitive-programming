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
ll t[N*4],lazy[N*4];
ll a[N];

void push(ll node,ll b,ll e){
    if(lazy[node]==-1){
        return;
    }

    t[node] = (e-b+1)*lazy[node];
    
    if(b!=e) {
      ll mid = (b+e)/2;
      ll l = 2*node, r = 2*node+1;
      lazy[l] = lazy[node];
      lazy[r] = lazy[node];
   }

   lazy[node] = -1;
}

void build(ll node,ll b,ll e){

    lazy[node] = -1;
    if(b==e){
        t[node] = a[b];
        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*node,r = 2*node+1;
    build(l,b,mid);
    build(r,mid+1,e);

    t[node] = t[l]+t[r];
}

void update(ll node,ll b,ll e,ll i,ll j,ll x){
    push(node,b,e);
    if(b>j or e<i) return;
    if(b>=i and e<=j){
       lazy[node] = x;
       push(node,b,e);
       return; 
    }

    ll mid = (b+e)/2;
    ll l = 2*node,r = 2*node+1;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);

    t[node] = t[l]+t[r];

}

ll query(ll node,ll b,ll e,ll i,ll j){
    push(node,b,e);
    if(b>j or e<i) return 0;
    if(b>=i and e<=j){
        return t[node];
    }

    ll mid = (b+e)/2;
    ll l = 2*node,r = 2*node+1;
    return query(l,b,mid,i,j) + query(r,mid+1,e,i,j);
}

void solve()
{
   ll n,q;
   cin>>n>>q;
   build(1,1,n);
   while(q--){
       ll type;
       cin>>type;

       if(type ==1){
          ll l,r,x;
          cin>>l>>r>>x;
          update(1,1,n,l+1,r,x);
       }

       else{
          ll ind;
          cin>>ind;
          cout<<query(1,1,n,ind+1,ind+1)<<endl;
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


//https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C

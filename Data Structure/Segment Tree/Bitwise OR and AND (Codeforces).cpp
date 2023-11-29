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
#define mod 1000000007
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define INF (ll)1000000000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const ll N = 1e5+9;
ll a[N];
ll t[N*4],lazy[N*4];

void push(ll n, ll b, ll e){
   if(lazy[n] == 0) return;

   t[n] = (t[n]|lazy[n]);
   
   if(b!=e){
        ll mid = (b+e)/2;
        ll l = 2*n, r = 2*n+1;
        lazy[l] = (lazy[l]|lazy[n]);
        lazy[r] = (lazy[r]|lazy[n]);
   }

   lazy[n] = 0;
}

void build(ll n,ll b,ll e){
    lazy[n] = 0;
    if(b==e){
       t[n] = a[b];
       return;
    }

    ll mid = (b+e)/2;
    ll l = 2*n,r = 2*n+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n] = (t[l]&t[r]);
}

void update(ll n, ll b, ll e, ll i, ll j, ll x){
    push(n,b,e);
    if(b>j or e<i) return;
    if(b>=i and e<=j){
        lazy[n] = x;
        push(n,b,e);
        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*n, r = 2*n+1;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);
    t[n] =( t[l] &t[r]);
}

ll query(ll n,ll b, ll e, ll i, ll j){
    push(n,b,e);

    if(b>j or e<i) return 2147483647;

    if(b>=i and e<=j){
        return t[n];
    }

    ll mid = (b+e)/2;
    ll l = 2*n, r = 2*n+1;
    
    ll t1 = query(l,b,mid,i,j);
    ll t2 = query(r,mid+1,e,i,j);
    return (t1&t2);
}


void solve()
{
   ll n,q;
   cin>>n>>q;
   for(ll i=1;i<=n;i++){
      a[i] =0;
   }
   build(1,1,n);

   while(q--){
     ll type;
     cin>>type;
     if(type == 1) {
        ll l, r, v;
        cin>>l>>r>>v;
        update(1,1,n,l+1,r,v);
     }

     else {
        ll l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l+1,r)<<endl;
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


//https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C

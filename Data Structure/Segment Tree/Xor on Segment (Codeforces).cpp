// https://codeforces.com/contest/242/problem/E 

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


struct node{
    ll on[20],off[20];
};

const ll N = 1e5+5;
ll a[N], lazy[N*4];
node t[N*4];


void push(ll n,ll b,ll e){
    if(lazy[n] == 0) return;

    for(ll i=0;i<20;i++){
        if((lazy[n]>>i) & 1){
            swap(t[n].on[i],t[n].off[i]);
        }
    }

    if(b!=e){
        ll mid = (b+e)/2;
        ll l = 2*n, r = 2*n+1;

        lazy[l] ^= lazy[n];
        lazy[r] ^= lazy[n];
    }

    lazy[n] = 0;
}

node merge(node l, node r) {
    node ans;
    for(ll i = 0;i<20;i++){
        ans.on[i] = (l.on[i] + r.on[i]);
        ans.off[i] =( l.off[i] + r.off[i]);
    }

    return ans;
}

void build(ll n,ll b,ll e){
    lazy[n] = 0;
    if(b==e){
        for(ll i=0;i<20;i++){
            if((a[b]>>i) & 1){
                t[n].on[i] = 1;
                t[n].off[i] = 0;
            }

            else {
                t[n].on[i] = 0;
                t[n].off[i] = 1;
            }
        }

        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*n, r = 2*n+1;
    build(l,b,mid);
    build(r,mid+1,e);

    t[n] = merge(t[l],t[r]);
}

void update(ll n, ll b, ll e, ll i, ll j, ll x) {
    push(n,b,e);
    if(b>j or e<i) return ;
    if(b>=i and e<=j){
        lazy[n] = x;
        push(n,b,e);
        return;
    }

    
    ll mid = (b+e)/2;
    ll l = 2*n, r = 2*n+1;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);

    t[n] = merge(t[l],t[r]);
    
}

node query(ll n,ll b, ll e, ll i, ll j){
    push(n,b,e);
    if(b>j or e<i){
        node val;
        memset(val.on,0,sizeof val.on);
        memset(val.off,0,sizeof val.off);
        return val;
    }

    if(b>=i and e<=j){
        return t[n];
    }

    ll mid = (b+e)/2;
    ll l = 2*n, r = 2*n+1;

    return merge(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}

void solve()
{
   ll n;
   cin>>n;
   for(ll i=1;i<=n;i++) cin>>a[i];
   build(1,1,n);


   ll q;
   cin>>q;

   while(q--){
      ll type;
      cin>>type;
      if(type == 1){
         ll l,r ;
         cin>>l>>r;
         node ans = query(1,1,n,l,r);
         ll sum = 0;
         
         for(ll i=0;i<20;i++){
            sum+=(ans.on[i]*(1<<i));
         }

         cout<<sum<<endl;
      }

      else {
         ll l,r,v;
         cin>>l>>r>>v;
         update(1,1,n,l,r,v);
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

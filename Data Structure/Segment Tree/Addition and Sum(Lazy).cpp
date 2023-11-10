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

const int N = 1e5+9;
ll a[N];

struct node {
    ll prop,val;
};

node t[N*4];

void build(int node,int b, int e) {
   if(b==e) {
      t[node].val = a[b];
      //t[node].prop = 0;
      return;
   }
   int l = 2*node;
   int r = 2*node+1;
   int mid = (b+e)/2;
   build(l,b,mid);
   build(r,mid+1,e);
   
   t[node].val = t[l].val + t[r].val;
   //t[node].prop = 0;
}


void update(ll node,ll b,ll e,ll i,ll j,ll x){
    if(b>j or e<i) return;
    if(b>=i and e<=j){
        t[node].val +=((e-b+1)*x);
        t[node].prop += x;
        return;
    }
    ll mid = (b+e)/2;
    ll l = 2*node,r = 2*node+1;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);
    t[node].val = t[l].val + t[r].val + (e-b+1)*t[node].prop;
}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry){
     if(b>j or e<i) return 0;
     if(b>=i and e<=j){
        return t[node].val+((e-b+1)*carry);
     }

     ll mid = (b+e)/2;
     ll l = 2*node;
     ll r = 2*node+1;

     ll t1 = query(l,b,mid,i,j,carry+t[node].prop);
     ll t2 = query(r,mid+1,e,i,j,carry+t[node].prop);
     return t1 + t2;
}

void solve()
{
   ll n,q;
   cin>>n>>q;
   
   //for(ll i=1;i<=n;i++)cin>>a[i];
   build(1,1,n);
   //cout<<t[1].val<<endl;
   
   for(ll i=1;i<=q;i++){
      ll type;
      cin>>type;
      if(type ==1){
         ll i, j, v;
         cin>>i>>j>>v;
         update(1,1,n,i+1,j,v);
      }

      else{
        ll i,j;
        cin>>i>>j;
        cout<<query(1,1,n,i+1,j,0)<<endl;
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

//https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/D

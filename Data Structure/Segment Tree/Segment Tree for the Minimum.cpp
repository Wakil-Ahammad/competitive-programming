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
ll a[N];
ll t[N*4];

void build(ll node,int b, int e) {
   if(b==e) {
      t[node] = a[b];
      return;
   }
   ll l = 2*node;
   ll r = 2*node+1;
   ll mid = (b+e)/2;
   build(l,b,mid);
   build(r,mid+1,e);
   
   t[node] = min(t[l],t[r]);
}

ll query(ll node, ll b, ll e, ll i, ll j){
   if(b>j || e<i) return INT_MAX;
   if(b>=i && e<=j) return t[node];
   ll l = 2*node;
   ll r = 2*node+1;
   ll mid = (b+e)/2;
   return min(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}

void Update(ll node, ll b, ll e, ll i, ll x) {
   if(b>i || e<i) return;
   if(b==i && e==i)
   {
      t[node] = x;
      return;
   }

   ll l = 2*node;
   ll r = 2*node+1;
   ll mid = (b+e)/2;
   Update(l,b,mid,i,x);
   Update(r,mid+1,e,i,x);
   t[node] = min(t[l],t[r]);
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  ll n,m; 
  cin>>n>>m;

  for(ll i=1;i<=n;i++)cin>>a[i];
  build(1,1,n);
  
  //for(ll i=1;i<=9;i++){cout<<t[i]<<" ";cout<<endl;}
  while(m--)
  {
     ll q;
     cin>>q;

     if(q==1){
        ll ind,val;
        cin>>ind>>val;
        Update(1,1,n,ind+1,val);
     }

     else {
        ll  i,j;
        cin>>i>>j;
        cout<<query(1,1,n,i+1,j)<<endl;
     }
  }

}

//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

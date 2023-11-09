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

const ll N = 1e5+5,inf = 1e9+9;
ll a[N];

struct node{
   ll mn,count;
};

node t[N*4];

node merge(node l,node r)
{
   node ans;
   ans.mn = min(l.mn,r.mn);
   ans.count = 0;

   if(l.mn == ans.mn)
   {
      ans.count+=l.count;
   }

   if(r.mn == ans.mn)
   {
      ans.count+=r.count;
   }

   return ans;
}

void build(ll node,ll b,ll e) {

   if(b==e){
     t[node].mn = a[b];
     t[node].count = 1;
     return;
   }
   ll l = 2*node,r = 2*node+1;
   ll mid = (b+e)/2;
   build(l,b,mid);
   build(r,mid+1,e);
   t[node] = merge(t[l],t[r]);
}

void upd(ll node,ll b,ll e,ll i,ll x){
   
   if(b>i || e<i) return;

   if(b==e)
   {
      t[node].mn = x;
      t[node].count =1;
      return;
   }

   ll l = 2*node,r = 2*node+1;
   ll mid = (b+e)/2;
   upd(l,b,mid,i,x);
   upd(r,mid+1,e,i,x);
   t[node] = merge(t[l],t[r]);
}

node query(ll node,ll b,ll e,ll i,ll j)
{
   if(b>j or e<i) return {inf, 1};
   if(b>=i && e<=j) return t[node];
   ll mid = (b+e)/2;
   ll l = 2*node,r = 2*node+1;

   return merge(query(l,b,mid,i,j),query(r,mid+1,e,i,j));

}


void solve()
{
   ll n,q;
   cin>>n>>q;

   for(ll i=1;i<=n;i++) cin>>a[i];
   
   build(1,1,n);

   while(q--)
   {
      ll x;
      cin>>x;
      if(x==1){
         ll i, v;
         cin>>i>>v;
         upd(1,1,n,i+1,v);
      }
      
      else{
         ll l,r;
         cin>>l>>r;
         node ans = query(1,1,n,l+1,r);
         cout<<ans.mn<<" "<<ans.count<<endl;
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

//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C

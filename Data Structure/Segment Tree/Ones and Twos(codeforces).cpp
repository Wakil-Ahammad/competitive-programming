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

void build(ll n,ll b,ll e){
    if(b==e){
        t[n] = a[b];
        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*n,r = 2*n+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n] = t[l] + t[r];
}

void update(ll n,ll b,ll e,ll i,ll x){
    if(b>i or e<i) return;
    if(b==e){
        a[b] = x;
        t[n] = a[b];
        return;
    }

    ll mid = (b+e)/2;
    ll l = 2*n,r = 2*n+1;
    update(l,b,mid,i,x);
    update(r,mid+1,e,i,x);
    t[n] = t[l] + t[r];
}

ll query(ll n,ll b,ll e,ll i,ll j){
    if(b>j or e<i) return 0;
    if(b>=i and e<=j){
        return t[n];    
    }

    ll mid = (b+e)/2;
    ll l = 2*n,r = 2*n+1;
    return query(l,b,mid,i,j) + query(r,mid+1,e,i,j);
}


void solve()
{
   ll n,q;
   cin>>n>>q;
   
   for(ll i=1;i<=n;i++)cin>>a[i];
   build(1,1,n);

   while(q--){
      ll type;
      cin>>type;
      if(type==1){
         ll x;
         cin>>x;
         ll sum = query(1,1,n,1,n);

         if(x>sum){NO;continue;}
      
         if(sum%2 == x%2){
             YES;
             continue;
         }

         ll l =1;
         while(l<=n && a[l]!=1){l++;}
         if(l>n){NO;continue;}

         ll r = n;
         while(r>=1 && a[r]!=1){r--;}
         if(r<1){NO;continue;}

         if(l<=n){
            ll val = query(1,1,n,l,n);
            if(val>=x){
                YES;
                continue;
            }
         }

         if(r>=1){
            ll val = query(1,1,n,1,r);
            if(val>=x){
                YES;
                continue;
            }
         }

         NO;
      }

      else{
         ll ind,v;
         cin>>ind>>v;
         update(1,1,n,ind,v);
      }
   }


}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t;
  cin>>t;
  while(t--)
  {
     solve();
  }
    
}

//https://codeforces.com/contest/1896/problem/D

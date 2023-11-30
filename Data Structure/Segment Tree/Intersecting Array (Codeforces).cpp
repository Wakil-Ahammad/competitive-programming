// https://codeforces.com/contest/482/problem/B

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
int l[N],r[N],req[N];
int ans[N];
int t[N*4];
int a[N];

void build(int n,int b,int e){
    if(b==e){
        t[n] = ans[b];
        return;
    }

    int mid = (b+e)/2;
    int l = 2*n, r= 2*n+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n] = t[l] & t[r];
}

int query(int n, int b, int e, int i, int j){
    if(b>j or e<i) return (1<<30)-1;
    if(b>=i and e<=j){
        return t[n];
    }
    
    
    int mid = (b+e)/2;
    int l = 2*n, r= 2*n+1;

    return query(l,b,mid,i,j) & query(r,mid+1,e,i,j);

}

void solve()
{
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=q;i++){
        cin>>l[i]>>r[i]>>req[i];
    }

    for(int k = 0; k<30; k++){
        for(int i=1;i<=n;i++){a[i] = 0;}

        for(int i=1;i<=q;i++){
            if(((req[i]>>k) & 1)==1){
               a[l[i]]++;
               a[r[i]+1]--;
            }
        }

        for(int i=1;i<=n;i++){
            a[i] += (a[i-1]);
        }

        for(int i=1;i<=n;i++){
            if(a[i]> 0){
               ans[i] |=( 1<<k);
            }
        }
    }

        build(1,1,n);

         for(int i=1;i<=q;i++){
            int val = query(1,1,n,l[i],r[i]);
            if(val != req[i]){
                NO;
                return;
            }
        }

    YES;

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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

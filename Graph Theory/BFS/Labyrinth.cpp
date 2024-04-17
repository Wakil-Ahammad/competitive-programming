// grid bfs(shortest path)
// https://cses.fi/problemset/task/1193

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
#define INF (ll)100000000000
#define all(x) x.begin(),x.end()
//#define end cout<<endl
#define bcntz __builtin_ctz
#define fl(i,n) for(int i=0;i<n;i++)
using namespace std;
#define st(s) sort(s.begin(),s.end())

const ll N = 1002;
ll dx[] = {0,0,+1,-1};
ll dy[] = {+1,-1,0,0};

char grid[N][N];
ll vis[N][N];
ll n,m;
ll d[N][N];
pair<ll,ll> par[N][N];

bool valid(ll r, ll c){
   return r>=0 && r<n && c>=0 && c<m &&  grid[r][c] != '#' && !vis[r][c];
}

void bfs(pair<ll,ll>start){
    
    queue<pair<int,int>>q;
    q.push({start.first,start.second});
    d[start.first][start.second]=0;
    vis[start.first][start.second] = 1;
    
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        ll x = v.first;
        ll y = v.second;

        for(ll i=0;i<4;i++){
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if(valid(nx,ny)){
                d[nx][ny] = d[x][y] + 1;
                par[nx][ny] = {x,y};
                q.push({nx,ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

void solve()
{
   cin>>n>>m;
   pair<ll,ll>start,end;
   
   for(ll i=0;i<n;i++){
      for(ll j=0;j<m;j++){
          cin>>grid[i][j];
          if(grid[i][j]=='A'){
             start.first = i;
             start.second = j;
          }

          else if(grid[i][j]=='B'){
            end.first = i;
            end.second = j;
          }
      }
   }

   for(ll i=0;i<n;i++){
      for(ll j=0;j<m;j++) d[i][j] = INF;
   }

   bfs(start);

   ll ans = d[end.first][end.second];
   if(ans == INF){
     NO;
     return;
   }

   YES;
   cout<<ans<<endl;
   
   vector<pair<ll,ll>> path;
   auto cur = end;
   while(cur != start){
      path.push_back(cur);
      cur = par[cur.first][cur.second];
   }

   path.push_back(start);

   reverse(path.begin(), path.end());

   for(ll i=0;i<path.size()-1;i++){
      ll xi = path[i+1].first - path[i].first;
      ll yi = path[i+1].second - path[i].second;

      if(xi == +1) cout<<'D';
      if(xi == -1) cout<<'U';
      if(yi == +1) cout<<'R';
      if(yi == -1) cout<<'L';
   }

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

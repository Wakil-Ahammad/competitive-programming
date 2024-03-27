// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=513

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

const int N = 102;
char grid[N][N];
int vis[N][N];
int dr[] = {-1,+1,0,0,+1,-1,-1,+1};
int dc[] = {0,0,-1,+1,+1,-1,+1,-1};
int n,m;

bool valid(int r, int c){
   return r>=0 && r<n && c>=0 && c<m && grid[r][c] == '@' && !vis[r][c];
}

void dfs(int r, int c){
    vis[r][c] = 1;

    for(int i=0;i<8;i++){
       ll nr = r + dr[i];
       ll nc = c + dc[i];
       if(valid(nr,nc)) dfs(nr,nc);
    }

}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  while(1)
  {
     cin>>n>>m;
     if(n==0 && m==0 ) break;
     memset(vis,0,sizeof vis);
     for(int i=0;i<n;i++) cin>> grid[i];
     
     int cmp = 0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '@' && !vis[i][j]){
                dfs(i,j);
                cmp++;
            }
        }
     }

     cout<<cmp<<endl;
  }
    
}

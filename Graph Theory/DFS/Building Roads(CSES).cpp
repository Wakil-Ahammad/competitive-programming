// https://cses.fi/problemset/task/1666

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+10;
vector<int>g[N];
bool vis[N];

void dfs(int vertex)
{
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        if(vis[child])continue;
        dfs(child);
    }
}

int main(){
 int n,e;
 cin>>n>>e;
 for(int i=0;i<e;i++)
 {
     int v1,v2;
     cin>>v1>>v2;
     g[v1].push_back(v2);
     g[v2].push_back(v1);
 }

 int cnt=0;

 vector<int>ans;

 for(int i=1;i<=n;i++)
 {
     if(vis[i])continue;
     dfs(i);

     ans.pb(i);
     cnt++;

 }

 cout<<cnt-1<<endl;

 for(int i=0;i<ans.size()-1;i++)
 {
   cout<<ans[i]<<" "<<ans[i+1]<<endl;
 }

}

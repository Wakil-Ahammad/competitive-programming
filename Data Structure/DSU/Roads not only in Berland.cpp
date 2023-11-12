#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int par[N],sz[N];

void make_set(int n){
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int u){
    if(par[u] == u) return u;
    return par[u] = find_set(par[u]);
}

void union_set(int u,int v){
    int a = find_set(u);
    int b = find_set(v);

    if(sz[a]<sz[b]) swap(a,b);

    if(a!=b){
        par[b] = a;
        sz [a] +=sz[b];
    }
}


void solve()
{
   int n;
   cin>>n;
   make_set(n);
  
   vector<pair<int,int>>extra;

   for(int i=1;i<n;i++){
      int u,v;
      cin>>u>>v;
      if(find_set(u) == find_set(v)){
         extra.push_back({u,v});
      }
      else{
        union_set(u,v);
      }
   }

   set<int>st;
   
   for(int i=1;i<=n;i++){
      st.insert(find_set(i));
   }

   if(st.size() == 1) {cout<<0<<endl;return;}

   vector<int>v;

   for(auto i:st){
      v.push_back(i);
   }
   
   cout<<extra.size()<<endl;
   for(int i=0;i<extra.size();i++){
      cout<<extra[i].first<<" "<<extra[i].second<<" "<<v[0]<<" "<<v[i+1]<<endl;
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


// https://codeforces.com/problemset/problem/25/D

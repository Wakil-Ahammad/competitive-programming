// https://lightoj.com/problem/neighbor-house

#include<bits/stdc++.h>
using namespace std;

const int N = 22, inf = 1e9;
int dp[N][4], n, cost[N][3];
int f(int i, int last) {
  if (i == n + 1) {
    return 0;
  }
  int &ans = dp[i][last];
  if (ans != -1) return ans;
  ans = inf;
  for (int col = 0; col < 3; col++) {
    if (col != last) {
      ans = min(ans, cost[i][col] + f(i + 1, col));
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    memset(dp, -1, sizeof dp);
    cout << "Case " << ++cs << ": " << f(1, 3) << '\n';
  }
  return 0;
}

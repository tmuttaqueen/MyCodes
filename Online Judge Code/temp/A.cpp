/**
 *    author:  tourist
 *    created: 23.03.2019 14:09:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long A, B;
  cin >> n >> A >> B;
  vector<int> a(n + 2);
  a[0] = 0; a[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<long long> dp(n + 2);
  dp[0] = 0;
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = (long long) 1e18;
    int bigger = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] < a[i]) {
        dp[i] = min(dp[i], dp[j] + bigger * A + (i - 1 - j - bigger) * B);
        cout << j << " i " << i << " " << bigger << " dp[i] " << dp[i] << " dp[j] " << dp[j] << endl;
      } else {
        bigger++;
      }
    }
    cout << i << ": " << dp[i] << endl;;
  }
  cout << endl;
  cout << dp[n + 1] << '\n';
  return 0;
}

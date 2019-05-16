#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = (int)1e9 + 5;



int main() {
#ifdef LOCAL

#else

#endif

	int n;
	scanf("%d", &n);
	vector<vector<double>> p(n, vector<double>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lf", &p[i][j]);
		}
	}

	auto dp = vector<vector<double>>(n, vector<double>(1 << n));

	for (int mask = 0; mask < (1 << n); mask++) {
		if (mask == 0) {
			dp[0][mask] = 1;
			continue;
		}
		for (int who = 0; who < n; who++) {
			if ((mask & (1 << who)) != 0) continue;
			double & cur = dp[who][mask];
			for (int nxt = 0; nxt < n; nxt++) {
				if ((mask & (1 << nxt)) != 0) {
					cur = max(cur, dp[nxt][mask ^ (1 << nxt)] * p[nxt][who] + dp[who][mask ^ (1 << nxt)] * p[who][nxt]);
				}
			}
		}
	}

	double best = 0;

	for (int st = 0; st < n; st++) {
		best = max(best, dp[st][((1 << n) - 1) ^ (1 << st)]);
	}

	printf("%.20f\n", best);

}

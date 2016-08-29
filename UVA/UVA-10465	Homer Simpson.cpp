#include<bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int dp[10010];
	int n, m, t;
	while(scanf("%d %d %d", &m, &n, &t) != EOF) {
		int inf = 1<<25;
		for(int i = 1; i < m; i++)
			dp[i] = - inf;
		dp[0] = 0;

		for(int i = m; i <= t; i++) {
			dp[i] = dp[i - m] + 1;
		}

		for(int i = n; i <= t; i++) {
			dp[i] = max(dp[i], dp[i - n] + 1);
		}
		int i = t;
		while(dp[i] < 0)
			i--;
		printf("%d", dp[i]);
		if(i != t)
			printf(" %d", t - i);
		printf("\n");
	}

	return 0;
}

































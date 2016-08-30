#include<bits/stdc++.h>
using namespace std;
 
int dp[60][1010];
int n, t;
int tt[60][60], cost[60][60];
 
 
pair<int, int> solve2() {
 
	int inf = 1<<25;
	for(int i = 0; i < n; i++) {
		dp[i][0] = inf;
	}
	dp[n - 1][0] = 0;
 
 
	for(int i = 1; i <= t; i++) {
		for(int j = 0; j < n; j++) {
			dp[j][i] = inf;
			for(int k = 0; k < n; k++) {
				int l = i - tt[j][k];
				if(l >= 0) {
					dp[j][i] = min(dp[j][i], dp[k][l] + cost[j][k]);
				}
			}
		}
	}
 
	int ans = inf;
	int indx = -1;
	for(int i = 0; i <= t; i++) {
		if(ans > dp[0][i]) {
			ans = dp[0][i];
			indx = i;
		}
	}
	return make_pair(ans, indx);
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
 
	while(scanf("%d %d", &n, &t) && (n || t)) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d",&tt[i][j]);
			}
		}
 
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d",&cost[i][j]);
			}
		}
 
//		memset(dp1, -1, sizeof(dp1));
//		auto ans = solve(0, 0);
		auto ans = solve2();
		printf("%d %d\n", ans.first, ans.second);
 
	}
 
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include<bits/stdc++.h>
using namespace std;
 
char x[10010], y[1010];
short dp[10010][1010];
int match[1010][30];
int b[1010];
int n, m;
 
 
 
 
int solve() {
 
	int q = b[1] = 0;
	for(int i = 1; i < m; i++) {
		while(q > 0 && y[q] != y[i])
			q = b[q];
		q += (y[q] == y[i]);
		b[i + 1] = q;
	}
 
 
	for(char c = 'a'; c <= 'z'; c++) {
		for(int i = 0; i < m; i++) {
			int k = i;
			while(k > 0 && y[k] != c)
				k = b[k];
			k+= (y[k] == c);
			match[i][c - 'a'] = k;
		}
	}
 
	for(int i = 0; i <= n; i++) {
		dp[i][m] = n;
	}
	for(int i = 0; i < m; i++) {
		dp[n][i] = 0;
	}
 
	for(int i = n - 1; i >= 0; i--) {
		for(int k = 0; k < m; k++) {
			dp[i][k] = dp[i + 1][k] + 1;
			int g = match[k][x[i] - 'a'];
			dp[i][k] = min(dp[i][k], dp[i + 1][g]);
//			printf("%d %d %d %d\n", i, k, g, dp[i][k]);
 
		}
	}
 
//	for(int i = 0; i < n; i++) {
//		printf("%d  ", i);
//		for(int j = 0; j < m; j++)
//			printf("%d ", dp[i][j]);
//		printf("\n");
//	}
 
	return dp[0][0];
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	while(scanf("%s", x) != EOF) {
		scanf("%s", y);
 
		n = strlen(x);
		m = strlen(y);
 
 
		short ans = solve();
		cout<<ans<<endl;
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

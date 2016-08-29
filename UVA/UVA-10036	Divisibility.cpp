#include<bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int t, n, k;
	scanf("%d", &t);
	int a[10010];
	bool dp[10010][110];

	while(t--) {
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		for(int i = 1; i < k; i++) {
			dp[n][i] = 0;
		}
		dp[n][0] = 1;

		for(int i = n - 1; i > 0; i--) {
			for(int j = 0; j < k; j++) {
				int g = k + j;
				dp[i][j] = dp[i + 1][(a[i] % k + g) % k];
				dp[i][j] |= dp[i + 1][(-a[i] % k + g) % k];
			}
		}

//		for(int i = 1; i <= n; i++) {
//			for(int j = 0; j < k; j++) {
//				printf("%d ", dp[i][j]);
//			}
//			printf("\n");
//		}

		if(dp[1][(a[0] % k + k) % k]) {
			printf("Divisible\n");
		}
		else {
			printf("Not divisible\n");
		}

	}



	return 0;
}

































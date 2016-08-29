#include<bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int dp[1010][1010];
	char s1[1010], s2[1010];
	int n, m;
	for(int i = 0; i < 1010; i++) {
		dp[i][0] = dp[0][i] = 0;
	}

	while(gets(s1) && gets(s2)) {
		n = strlen(s1);
		m = strlen(s2);



		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if(s1[i - 1] == s2[j - 1])
					dp[i][j] =  max(dp[i][j], dp[i - 1][j - 1] + 1);

			}
		}

		printf("%d\n", dp[n][m]);

	}



	return 0;
}

































#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);


	int a[110][110];
	memset(a, 0, sizeof(a));
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					scanf("%d", &a[i][j]);
					a[i][j] += a[i - 1][j];
				}
			}

			int ans = INT_MIN;

			for(int i = 1; i <= n; i++) {
				for(int j = i; j <= n; j++) {
					int s = 0;
					for(int k = 1; k <= n; k++) {
						s += a[j][k] - a[i - 1][k];
						ans = max(ans, s);
						s = max(s, 0);
					}
				}
			}

			printf("%d\n", ans);
	}



	return 0;
}





































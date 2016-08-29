#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);


	long long a[120][120];
	memset(a, 0, sizeof(a));
	int tc;
	scanf("%d", &tc);
	int n, m, b;
	long long k;
	for(int cc = 1; cc <= tc; cc++) {
		scanf("%d %d %lld", &n, &m, &k);

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%lld", &a[i][j]);
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}

		int ans = 0;
		long long cost = 0;
		for(int r1 = 1; r1 <= n; r1++) {
			for(int r2 = r1; r2 <= n; r2++) {
				for(int c1 = 1; c1 <= m; c1++) {
					for(int c2 = c1; c2 <= m; c2++) {
						long long s = a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] +
								a[r1 - 1][c1 - 1];
						if(s <= k) {
							long long area = (r2 - r1 + 1) * (c2 - c1 + 1);
							if(area > ans) {
								ans = area;
								cost = s;
							}
							else if(area == ans)
								cost = min(cost, s);

						}

					}
				}
			}
		}

		printf("Case #%d: %d %lld\n", cc, ans, cost);

	}

	return 0;
}





































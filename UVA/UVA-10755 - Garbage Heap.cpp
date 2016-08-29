#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);
	long long a[25][25][25];
	memset(a, 0, sizeof(a));

	while(tc--) {

		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		long long totoal = 0;
		for(int i = 1; i <= x; i++) {
			for(int j = 1; j <= y; j++) {
				for(int k = 1;k <= z; k++) {
					scanf("%lld", &a[i][j][k]);
					totoal += a[i][j][k];
					a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] - a[i - 1][j - 1][k];
//					printf("%d\n", a[i][j][k]);
				}
			}
		}

		long long ans = LONG_MIN;

		for(int r1 = 1; r1 <= x; r1++) {
			for(int r2 = r1; r2 <= x; r2++) {
				for(int k1 = 1; k1 <= y; k1++) {
					for(int k2 = k1; k2 <= y; k2++) {
						long long s = 0;
						long long t = LONG_MIN;
						for(int j = 1; j <= z; j++) {
							s += a[r2][k2][j] - a[r2][k1 - 1][j]
								- a[r1 - 1][k2][j] + a[r1 - 1][k1 - 1][j];
							t = max(t, s);
							s = max(s, (long long)0);
//							printf("%d %d\n", a[r2][k2][z], a[r1][k1][z]);
						}
//						printf("%d %d %d %d %d\n",r1, r2, k1, k2, t);
						ans = max(ans, t);
					}
				}
			}
		}


		printf("%lld\n", ans);
		if(tc != 0)
			printf("\n");

	}

	return 0;
}





































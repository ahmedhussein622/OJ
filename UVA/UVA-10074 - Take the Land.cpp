#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);


	int a[110][110];
	memset(a, 0, sizeof(a));
	int n, m, b, c;
	while(scanf("%d %d", &n, &m) && n && m) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%d", &b);
				if(b == 1)
					b = -1000000;
				else
					b = 1;
				a[i][j] = b + a[i - 1][j];
			}

		}


		int ans = 0;

		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				int s = 0;
				for(int k = 1; k <= m; k++) {
					s += a[j][k] - a[i - 1][k];
					s = max(s, 0);
					ans = max(ans, s);
				}
			}
		}


		printf("%d\n", ans);
	}



	return 0;
}





































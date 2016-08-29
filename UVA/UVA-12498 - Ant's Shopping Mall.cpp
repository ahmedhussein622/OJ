#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	for (int cc = 1; cc <= t; cc++) {

		printf("Case %d: ", cc);
		int r, c;
		scanf("%d %d\n", &r, &c);
		char a[r][c];
		bool fine = true;
		for(int i = 0; i < r; i++) {
			int w = 0;
			for(int j = 0; j < c; j++) {
				scanf("%c", &a[i][j]);
				w += a[i][j] == '1';
			}
			scanf("%*c");
			fine &= (w!=c);
		}
		if(!fine) {
			printf("-1");
		}
		else {
			int ans = 1<<25;
			for(int i = 0; i < c; i++) {
				int t = 0;
				for(int j = 0; j < r; j++) {
					int g = 1<<25;
					for(int k = i; k < c; k++) {
						if(a[j][k] == '0')
							g = min(g, k - i);
					}
					for(int k = i; k >= 0; k--) {
						if(a[j][k] == '0')
							g = min(g, i - k);
					}
					t += g;
				}
				ans = min(ans, t);
			}
			printf("%d", ans);
		}

		printf("\n");
	}

	return 0;
}














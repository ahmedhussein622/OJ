#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int n, d, r;
	int a[200];
	int b[200];
	int aa, bb;
	while(scanf("%d %d %d", &n, &d, &r) && (n || d || r)) {
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		for(int i = 0; i < n; i++) {
			scanf("%d", b + i);
		}

		sort(a, a + n);
		sort(b, b + n);

		int ans = 0;

		for(int i = 0; i < n; i++) {
			aa = a[i] + b[n - 1 - i];
			if(aa > d) {
				ans += (aa - d) * r;
			}
		}

		printf("%d\n", ans);

	}


	return 0;
}

































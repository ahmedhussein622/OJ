#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);
		int b[n];

		for (int i = 0; i < n; i++) {
			scanf("%d", b + i);
		}


		sort(b, b + n);

		int ans = 1 << 25;
		for(int i = b[0]; i <= b[n -1]; i++) {
			int s = 0;
			for(int j = 0; j < n; j++) {
				s += abs(i - b[j]);
			}
			ans = min(ans, s);
		}

		printf("%d\n", ans);

	}

	return 0;
}



#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int n;
	while(scanf("%d", &n) && n) {
		long long a[n];
		unordered_map<long long, int> s;
		for(int i = 0; i < n; i++) {
			scanf("%lld", a+i);
		}

		sort(a, a + n);
		for(int i = 0; i < n; i++) {
			s[a[i]] = i;
		}

		int ans;
		bool found = false;
		for(int i = n - 1; i >= 0 && !found; i--) {
			for(int j = n - 1; j >= 0 && !found; j--) {
				for(int k = n - 1; k >= 0 && !found; k--) {
					if(i !=j && i != k && j != k && s.find(a[i] - a[j] - a[k]) != s.end()) {
						int tt = s[a[i] - a[j] - a[k]];
						if(tt != i && tt != j && tt != k) {
							ans = a[i];
							found = true;
						}

					}
				}
			}
		}

		if(found) {
			printf("%d\n", ans);
		}
		else {
			printf("no solution\n");
		}
	}


	return 0;
}

































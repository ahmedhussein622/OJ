#include <bits/stdc++.h>


using namespace std;

int main() {


//	freopen("input.txt", "r", stdin);

	int n, q, a, b;

	int c = 1;
	while(scanf("%d %d", &n, &q) && (n || q)) {
		vector<int> v;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			v.push_back(a);
		}

		sort(v.begin(), v.end());

		printf("CASE# %d:\n", c++);
		for(int i = 0; i < q; i++) {
			scanf("%d", &a);
			auto it = lower_bound(v.begin(), v.end(), a);
			if(it == v.end() || *it != a) {
				printf("%d not found\n", a);
			}
			else {
				printf("%d found at %d\n", a, (it - v.begin()) + 1);
			}
		}
	}


	return 0;
}






























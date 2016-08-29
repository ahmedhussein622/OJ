#include <bits/stdc++.h>


using namespace std;

int main() {


//	freopen("input.txt", "r", stdin);

	int n, m, a, b;
	while(scanf("%d", &n) != EOF) {

		vector<int> v;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		scanf("%d", &m);

		auto end = lower_bound(v.begin(), v.end(), m);

		int diff = 1000000000;

		for(auto it = v.begin(); it != end; it++) {
			auto it2 = lower_bound(it, end, m - *it);
			if(it2 != end && *it2 == m - *it) {
//				printf("%d %d\n", diff, m - 2 * (*it));
				if(diff >  m - 2 * (*it)) {
					diff =  m - 2 * (*it);
					a = *it;
//					printf("found %d %d\n", *it, m -*it);
				}

			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", a, m - a);

	}


	return 0;
}






























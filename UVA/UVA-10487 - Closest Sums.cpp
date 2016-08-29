#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int n, m, a;
	int c = 1;
	while(scanf("%d", &n) && n) {

		set<int> s;
		int b[n];
		for(int i = 0; i < n; i++) {
			scanf("%d", b + i);
			for(int j = 0; j < i; j++) {
				s.insert(b[j] + b[i]);
			}
		}

//		for(auto it = s.begin(); it != s.end(); it++) {
//			printf("%d ", *it);
//		}
//		printf("\n");

		scanf("%d", &m);

		printf("Case %d:\n", c++);
		for(int i = 0; i < m; i++) {
			scanf("%d", &a);
			auto it = s.upper_bound(a);
			int ans = 1000000000;
			if(it != s.end())
				ans = *it;
			if(it != s.begin())
				it--;
			if(abs(*it - a) < abs(ans - a))
				ans = *it;
			printf("Closest sum to %d is %d.\n", a, ans);
		}

	}

	return 0;
}



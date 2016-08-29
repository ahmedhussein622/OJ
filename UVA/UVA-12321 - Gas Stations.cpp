#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int l, g, a, b, c, n, m;

	while(scanf("%d %d",&l, &g)&& (l || g)) {

		vector<pair<int, int>> v;
		for(int i = 0; i < g; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a - b, a + b));
		}

		sort(v.begin(), v.end());

		int c = 0;
		int indx = 0;
		int ans = 0;
		while(indx < g && c < l) {
			a = INT_MIN;
			while(indx < g && v[indx].first <= c) {
				a = max(a, v[indx].second);
				indx++;
			}
			if(a == INT_MIN)
				break;
			c = a;
			ans++;
		}

		if(c < l) {
			printf("-1\n");
		}
		else {
			printf("%d\n", g - ans);
		}


	}


	return 0;
}





































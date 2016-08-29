#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int a, b, c, n, m;
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		vector<pair<double, int >>	v;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(make_pair((double) a / b, i));
		}

		sort(v.begin(), v.end());
		printf("%d", v[0].second);
		for(int i = 1; i < v.size(); i++) {
			printf(" %d", v[i].second);
		}
		printf("\n");
		if(tc != 0)
			printf("\n");
	}


	return 0;
}





































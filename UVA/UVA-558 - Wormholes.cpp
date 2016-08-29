#include <bits/stdc++.h>


using namespace std;




int main() {


//	freopen("input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);
	int a, b, c;
	while(tc--) {

		int n, m;
		scanf("%d %d", &n, &m);
		int d[n];
		int inf = INT_MAX / 4;
		vector<pair<pair<int, int>, int>> adj;
		for(int i = 0; i < n; i++) {
			d[i] = inf;
		}

		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj.push_back(make_pair(make_pair(a, b), c));
		}


		d[0] = 0;

		int x, y, dd;
		for(int k = 1; k < n; k++) {
			for(int j = 0; j < m; j++) {
				auto p = adj[j];
				x = p.first.first;
				y = p.first.second;
				dd = p.second;
				d[y] = min(d[y], d[x] + dd);

			}
		}

		bool ans = false;
		for(int j = 0; j < m; j++) {
			auto p = adj[j];
			x = p.first.first;
			y = p.first.second;
			dd = p.second;
			if(d[y] >  d[x] + dd) {
				ans = true;
				break;
			}

		}

		if(ans) {
			printf("possible\n");
		}
		else {
			printf("not possible\n");
		}




	}





	return 0;
}







































#include <bits/stdc++.h>


using namespace std;


int main() {


//	freopen("input.txt", "r", stdin);

	int n, m, a, b, q, k;
	while(scanf("%d %d", &n, &m) && n) {

		vector<vector<int>> d;

		int ar[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &ar[i][j]);
			}
		}

		for(int i = 0; i < m; i++) {
			vector<int> v;
			for(int r = 0; r < n && i + r  < m; r++) {
				v.push_back(ar[r][i + r]);
			}
			d.push_back(v);
		}

		for(int i = 1; i < n; i++) {
			vector<int> v;
			for(int c = 0; c < m && i + c < n; c++) {
				v.push_back(ar[i + c][c]);
			}
			d.push_back(v);
		}

		k = d.size();
//		for(int i = 0; i < k; i++) {
//			sort(d[i].begin(), d[i].end());
//		}

		int q;
		scanf("%d", &q);

		for(int i = 0; i < q; i++) {
			scanf("%d %d", &a, &b);
			int ans = 0;
			for(int j = 0; j < k; j++) {
				vector<int> v = d[j];
				auto it1 = lower_bound(v.begin(), v.end(), a);
				auto it2 = upper_bound(v.begin(), v.end(), b);
				int diff = it2 - it1;
				if(it1 != v.end() && *it1 <= b && diff > ans) {
//					for(int tt = 0; tt < v.size(); tt++) {
//						printf("%d ", v[tt]);
//					}
//					printf("\n");
//					printf("kk %d %d %d %d\n", j, *it1, *it2, diff);
					ans = diff;
				}

			}
			printf("%d\n", ans);
		}
		printf("-\n");


	}


	return 0;
}






























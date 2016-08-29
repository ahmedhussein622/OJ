#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);

	int a, b, m;
	while(tc--) {

		scanf("%d", &m);

		vector<pair<int, int>> v;

		while(scanf("%d %d", &a, &b) && (a || b)) {
			v.push_back(make_pair(a, b));
		}

		sort(v.begin(), v.end());


		int c = 0;
		int indx = 0;

		vector<pair<int, int>> ans;
		while(c < m && indx < v.size()) {
//			printf("cc %d %d %d %d\n", c, indx, v[indx].first, v[indx].second);
			a = -100000000;
			b = -1;
			while(indx < v.size() && v[indx].first <= c) {
//				printf("%d %d %d\n",indx,  v[indx].first, v[indx].second);
				if(a < v[indx].second) {
					a = v[indx].second;
					b = indx;
				}
				indx++;
			}

			if(b != -1) {
				ans.push_back(v[b]);
				c = a;
			}
			else {
				break;
			}

		}

		if(c >= m) {
			printf("%d\n", ans.size());
			for(int i = 0; i < ans.size(); i++) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
		else {
			printf("0\n");
		}

		if(tc != 0)
			printf("\n");

	}




	return 0;
}

































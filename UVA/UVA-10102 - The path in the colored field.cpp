#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);


	int m;
	while(scanf("%d\n", &m) != EOF) {
		char a[m][m];
		vector<pair<int,int> > v;

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%c", &a[i][j]);
				if(a[i][j] == '3') {
					v.push_back(make_pair(i, j));
				}
			}
			scanf("%*c");
		}



		int ans = 0;

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] == '1') {
					int t = 1<<25;
					for(int k = 0; k < v.size(); k++) {
						t = min(t, abs(v[k].first - i) + abs(v[k].second - j));
					}
					ans = max(ans, t);
				}
			}
		}

		printf("%d\n", ans);


	}



	return 0;
}










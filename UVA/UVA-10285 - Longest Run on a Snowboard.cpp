#include<bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int a[110][110];
	int dp[110][110];
	int n, m, t;
	string s;

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	scanf("%d", &t);
	while(t--) {
		cin>>s>>n>>m;
		vector<pair<int, pair<int, int>>> v;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				v.push_back(make_pair(a[i][j], make_pair(i, j)));
				dp[i][j] = 1;
			}
		}

		sort(v.begin(), v.end());

		int ans = 1;
		for(int i = 0; i < v.size(); i++) {
			auto p = v[i];
			int x = p.second.first;
			int y = p.second.second;
			for(int j = 0; j < 4; j++) {
				int xn = x + dx[j];
				int yn = y + dy[j];
				if(xn >= 0 && xn < n && yn >= 0 && yn < m && a[xn][yn] < a[x][y]) {
					dp[x][y] = max(dp[x][y], dp[xn][yn] + 1);
				}
			}
			ans = max(ans, dp[x][y]);
		}

		cout<<s<<": "<<ans<<endl;

	}





	return 0;
}

































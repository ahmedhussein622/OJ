#include <bits/stdc++.h>


using namespace std;


int main() {


//	freopen("input.txt", "r", stdin);


	int tc;
	scanf("%d", &tc);
	int a, b, c;
	int n, m, t, e;

	int d[200];

	while(tc--) {

		scanf("%d", &n);
		scanf("%d", &e);
		scanf("%d", &t);
		scanf("%d", &m);

		e--;



		vector<vector<pair<int, int>>> adj;

		for(int i = 0; i < n; i++) {
			d[i] = INT_MAX;
			adj.push_back(vector<pair<int, int>> ());
		}


		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			adj[b].push_back(make_pair(a, c));
		}




		priority_queue<pair<int, int>> q;
		q.push(make_pair(0, e));
		d[e] = 0;


		while(!q.empty()) {
			auto p = q.top();
			q.pop();

			if(d[p.second] == -p.first) {
				for(int i = 0; i < adj[p.second].size(); i++) {
					auto v = adj[p.second][i];
					if(d[v.first] > d[p.second] + v.second) {
						d[v.first] = d[p.second] + v.second;
						q.push(make_pair(-d[v.first], v.first));
					}
				}
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(d[i] <= t)
				ans++;
//			printf("%d ", d[i]);
		}
//		printf("\n");
		printf("%d\n", ans);
		if(tc != 0)
			printf("\n");
	}


	return 0;
}







































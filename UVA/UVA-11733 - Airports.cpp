#include <bits/stdc++.h>


using namespace std;




int main() {


//	freopen("input.txt", "r", stdin);

	int n, m, k;
	int tc;
	scanf("%d", &tc);
	int a, b, c;
	int d[10010], visited[10010];
	for(int cc = 1; cc <= tc; cc++) {
		scanf("%d %d %d", &n, &m, &k);
		vector<vector<pair<int, int> > > adj;

		for(int i = 0; i <= n; i++) {
			adj.push_back(vector<pair<int, int> > ());
			d[i] = INT_MAX;
			visited[i] = 0;
		}

		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}


		priority_queue<pair<int, int> > q;

		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(!visited[i]) {
				ans++;
				d[i] = 0;
				q.push(make_pair(0, i));
				while(!q.empty()) {
					auto p = q.top();
					q.pop();
					visited[p.second] = 1;

//					printf("pop %d %d\n", p.second, p.first);
					if(d[p.second] == -p.first) {
						for(int i = 0; i < adj[p.second].size(); i++) {
							auto t = adj[p.second][i];
							if(!visited[t.first] && t.second < d[t.first]) {
								d[t.first] = t.second;
								q.push(make_pair(-t.second, t.first));
							}
						}
					}
				}

			}//if
		}

		int t = 0;
		for(int i = 1; i <= n; i++) {
//			printf("%d ", d[i]);
			if(d[i] >= k) {
				ans++;
			}
			else
				t += d[i];
		}
//		printf("\n");

		t = ans * k + t;
		printf("Case #%d: %d %d\n",cc, t, ans);
	}




	return 0;
}

























#include <bits/stdc++.h>
 
 
using namespace std;
 
 
 
void dijkestr(vector<vector<pair<int, int>>> & adj, int *d,
		int n, int m, int s, int t) {
 
	for(int i = 1; i <= n; i++) {
		d[i] = INT_MAX / 4;
	}
 
	d[s] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, s));
 
	while(!q.empty()) {
		auto p = q.top();
		q.pop();
		p.first *= -1;
 
		if(d[p.second] == p.first) {
			for(int i = 0; i < adj[p.second].size(); i++) {
				auto v = adj[p.second][i];
				if(d[v.first] > v.second + p.first) {
					d[v.first] = v.second + p.first;
					q.push(make_pair(-d[v.first], v.first));
				}
			}
		}
	}
 
}
 
 
int main() {
 
 
//	freopen("input.txt", "r", stdin);
 
 
	int tc;
	scanf("%d", &tc);
	int a, b, c;
	int n, m, k, s, t;
 
	int d1[10100], d2[10100];
 
	while(tc--) {
 
 
		scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
 
 
		vector<vector<pair<int, int>>> adj1, adj2;
 
 
		for(int i = 0; i <= n; i++) {
			adj1.push_back(vector<pair<int, int>> ());
			adj2.push_back(vector<pair<int, int>> ());
		}
 
 
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj1[a].push_back(make_pair(b, c));
			adj2[b].push_back(make_pair(a, c));
		}
 
 
		vector<pair<pair<int, int>, int>> vv;
		for(int i = 0; i < k; i++) {
			scanf("%d %d %d", &a, &b, &c);
			vv.push_back(make_pair(make_pair(a, b), c));
		}
 
		dijkestr(adj1, d1, n, m, s, t);
		if(d1[t] == INT_MAX / 4) {
			printf("-1\n");
		}
		else {
			dijkestr(adj2, d2, n, m, t, s);
			int ans = d1[t];
 
			for(int i = 0; i < k; i++) {
//				scanf("%d %d %d", &a, &b, &c);
//				vv.push_back(make_pair(make_pair(a, b), c));
				auto p = vv[i].first;
				int dd = vv[i].second;
				ans = min(ans, d1[p.first] + d2[p.second] + dd);
				ans = min(ans, d2[p.first] + d1[p.second] + dd);
			}
 
			printf("%d\n", ans);
		}
 
 
 
 
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

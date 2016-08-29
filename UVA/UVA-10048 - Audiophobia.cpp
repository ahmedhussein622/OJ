#include <bits/stdc++.h>


using namespace std;

int n, m;
int components;
int p[200], r[200];

void reset() {
	components = n;
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		r[i] = 0;
	}
}



int find(int x) {
	if(x == p[x])
		return x;
	return p[x] = find(p[x]);
}


bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y)
		return false;

	if(r[x] > r[y])
		p[y] = x;
	else {
		p[x] = y;
		r[y] += r[y] == r[x];
	}
	components--;
	return true;
}

bool visited[200];
int d[200][200];

void solve(vector<vector<pair<int, int>>> & g) {

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			d[i][j] = -1;
		}
	}

	for(int i = 1; i <= n; i++) {


		memset(visited, 0, sizeof(visited));
		d[i][i] = 0;

		queue<int> q;
		q.push(i);
		visited[i] = 1;


		while(!q.empty()) {
			int p = q.front();
			q.pop();

			for(int j = 0; j < g[p].size(); j++) {
				auto t = g[p][j];
				if(!visited[t.first]) {
					visited[t.first] = 1;
					q.push(t.first);
					d[i][t.first] = max(d[i][p], t.second);
				}
			}

		}


	}

//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			printf("%d ", d[i][j]);
//		}
//		printf("\n");
//	}



}

int main() {


//	freopen("input.txt", "r", stdin);
	int q;
	int a, b, c;
	int tc = 1;
	while(scanf("%d %d %d", &n, &m, &q) && (n || m || q)) {

		vector<pair<int, pair<int, int>>> adj;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj.push_back(make_pair(c, make_pair(a, b)));
		}

		sort(adj.begin(), adj.end());

		vector<vector<pair<int, int>>> g;
		for(int i = 0; i <= n; i++)
			g.push_back(vector<pair<int, int>>());

		reset();

		for(int i = 0; i < m && components != 1; i++) {
			auto p = adj[i];
			if(join(p.second.second, p.second.first)) {
				g[p.second.first].push_back(make_pair(p.second.second, p.first));
				g[p.second.second].push_back(make_pair(p.second.first, p.first));
			}
		}


		solve(g);

//		printf("comonentts %d\n", components);
//		for(int i = 1; i <= n; i++) {
//			printf("%d ", find(i));
//		}
//		printf("\n");

		if(tc != 1)
			printf("\n");
		printf("Case #%d\n", tc++);
		for(int i = 0; i < q; i++) {
			scanf("%d %d", &a, &b);
			if(d[a][b] != -1)
				printf("%d\n", d[a][b]);
			else
				printf("no path\n");
		}





	}



	return 0;
}







































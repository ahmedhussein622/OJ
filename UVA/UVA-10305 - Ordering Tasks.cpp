#include <bits/stdc++.h>


using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> order, visited;


void dfs(int node) {

	visited[node] = 1;

	for(int i = 0; i < adj[node].size(); i++) {
		int v = adj[node][i];
		if(visited[v] == 0)
			dfs(v);
	}
	order.push_back(node);
}


int main() {


//	freopen("input.txt", "r", stdin);

	int a, b;
	while(scanf("%d %d", &n, &m) && n) {
		adj.clear();
		visited.clear();
		for(int i = 0; i <= n; i++) {
			adj.push_back(vector<int> ());
			visited.push_back(0);
		}


		for(int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}

		order.clear();
		for(int i = 1; i <= n; i++) {
			if(!visited[i])
				dfs(i);
		}

		printf("%d", order[n - 1]);
		for(int i = n - 2; i >= 0; i--) {
			printf(" %d", order[i]);
		}
		printf("\n");

	}



	return 0;
}



























































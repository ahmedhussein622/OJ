#include<stack>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int adjMat[25][25];
//int visited[25][25];


int dfs(int node) {
	int ans = 0;

	for(int i = 0; i < n; i++) {
		if(adjMat[node][i] == 1) {
			adjMat[node][i] = adjMat[i][node] = 0;
			ans = max(ans, 1 + dfs(i));
			adjMat[node][i] = adjMat[i][node] = 1;
		}
	}


	return ans;
}


int main() {

//	freopen("input.txt", "r", stdin);


	int a, b;

	while(scanf("%d %d", &n, &m) && n && m) {
		memset(adjMat, 0, sizeof(adjMat));

		for(int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			adjMat[a][b] = adjMat[b][a] = 1;
		}


		int ans = 0;

		for(int i = 0; i < n; i++) {
			ans = max(ans, dfs(i));
		}

		printf("%d\n", ans);

	}




	return 0;
}
































#include <bits/stdc++.h>


using namespace std;


int p[1000100], r[1000100];
int components;


int find(int x) {
	if(p[x] == x)
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
		if(r[x] == r[y])
			r[y]++;
	}

	components--;
	return true;
}

int main() {


//	freopen("input.txt", "r", stdin);

	int n, m, k;
	int a, b, c;
	int tc = 0;
	while(scanf("%d", &n) != EOF) {

		int prev = 0;
		for(int i = 1; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			prev += c;
		}

		vector<pair<int, pair<int, int>>> adj;

		scanf("%d", &k);
		for(int i = 0; i < k; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj.push_back(make_pair(c, make_pair(a, b)));
		}
		scanf("%d", &m);

		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj.push_back(make_pair(c, make_pair(a, b)));
		}

		components = n;
		for(int i = 1; i <= n; i++) {
			p[i] = i;
			r[i] = 0;
		}

		sort(adj.begin(), adj.end());

		int ans = 0;
		for(int i = 0; i < adj.size() && components != 1; i++) {
			auto p = adj[i].second;
			if(join(p.first, p.second)) {
				ans += adj[i].first;
			}
		}


		if(tc != 0)
			printf("\n");
		tc++;

		printf("%d\n", prev);
		printf("%d\n", ans);




	}





	return 0;
}

























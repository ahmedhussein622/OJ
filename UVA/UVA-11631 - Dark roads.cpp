#include <bits/stdc++.h>


using namespace std;

int n, m;
int components;
int p[200100], r[200100];

void reset() {

	components = n;
	for(int i = 0; i < n; i++) {
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
		r[y] += (r[x] == r[y]);
	}
	return true;
}


int main() {


//	freopen("input.txt", "r", stdin);

	int a, b, c;

	while(scanf("%d %d", &n, &m) && (n || m)) {


		vector<pair<int, pair<int, int> > > adj;

		int ans = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			ans += c;
			adj.push_back(make_pair(c, make_pair(a, b)));
		}

		sort(adj.begin(), adj.end());


		reset();

		for(int i = 0; i < m && components != 1; i++) {
			auto p = adj[i];
			if(join(p.second.first, p.second.second)) {
				ans -= p.first;
			}
		}


		printf("%d\n", ans);

	}









	return 0;
}

























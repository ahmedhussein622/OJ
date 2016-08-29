#include <bits/stdc++.h>


using namespace std;

int n, m;
int p[510], r[510];
int components;

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
		r[y] += r[x] == r[y];
	}
	components--;
	return true;
}



int main() {


//	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	int s;
	int a, b;
	while(tc--) {
		scanf("%d %d", &s, &n);
		vector<pair<int, int>> v;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}

		vector<pair<double, pair<int, int>>> adj;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				double d = sqrt(pow(v[i].first - v[j].first, 2) +
						pow(v[i].second - v[j].second, 2));
				adj.push_back(make_pair(d, make_pair(i, j)));
			}
		}

		sort(adj.begin(), adj.end());
		m = adj.size();
		reset();
		double ans = 0;
		for(int i = 0; i < m && components != s; i++) {
			auto p = adj[i];
			if(join(p.second.first, p.second.second)) {
//				printf("%d %d %f\n", p.second.first, p.second.second, p.first);
				ans = max(ans, p.first);
			}
		}


		printf("%.2f\n", ans);



	}



	return 0;
}







































#include <bits/stdc++.h>


using namespace std;

int n, m;
int p[200], r[200];
int components;

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
		r[y] += r[x] == r[y];
	}
	components--;
	return true;
}




int main() {


//	freopen("input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);
	int a, b, c;

	while(tc--) {
		scanf("%d %d", &n, &m);

		vector<pair<int, pair<int, int>>> adj;

		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj.push_back(make_pair(c, make_pair(a, b)));
		}

		sort(adj.begin(), adj.end());

		bool f = false;
		int ans1 = 0;
		int indx;
		reset();
		vector<int> t;
		for(int i = 0; i < m && components != 1; i++) {
			auto p = adj[i];
			if(join(p.second.first, p.second.second)) {
				t.push_back(i);
				ans1 += p.first;
//				printf("(%d, %d) %d\n", p.second.first, p.second.second, p.first);
			}

		}


		int ans2 = INT_MAX;

		for(int k = 0; k < t.size(); k++) {
//			printf("kk %d %d\n", t[k], t.size());
			reset();
			int aa = 0;
			for(int i = 0; i < m && components != 1; i++) {
				if(i == t[k])
					continue;
				auto p = adj[i];
				if(join(p.second.first, p.second.second)) {
					aa += p.first;
//					printf("(%d, %d) %d\n", p.second.first, p.second.second, p.first);
				}

			}

			if(components == 1)
				ans2 = min(ans2, aa);

		}

		if(ans2 == INT_MAX)
			ans2 = ans1;

		printf("%d %d\n", ans1, ans2);




	}


	return 0;
}







































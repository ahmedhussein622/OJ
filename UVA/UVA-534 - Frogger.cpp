#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int tc = 1;
	int a, b, n;
	double d[500], p[500];
	bool out[500];
	while(scanf("%d", &n) && n) {
		vector<pair<int, int>> v;
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
			d[i] = INT_MAX;
			out[i] = 0;
		}

		priority_queue<pair<double, int>> q;
		d[0] = 0;
		q.push(make_pair(0.0, 0));

		while(!q.empty()) {
			auto pp = q.top();
			q.pop();
			if(!out[pp.second]) {
				out[pp.second] = 1;
				auto t = v[pp.second];
				for(int i = 0; i < n; i++) {
					if(i == pp.second || out[i])
						continue;

					double dd = sqrt(pow(t.first - v[i].first, 2) +
							pow(t.second - v[i].second, 2));
					if(d[i] > dd) {
						p[i] = pp.second;
						d[i] = dd;
						q.push(make_pair(-dd, i));
					}

				}
			}
		}

		double ans = 0;
		int node = 1;
		while(node != 0) {
//			printf("%d %d %d %f\n",node, v[node].first, v[node].second, d[node]);
			ans = max(ans, d[node]);
			node = p[node];
		}

		printf("Scenario #%d\n", tc++);
		printf("Frog Distance = %.3f\n\n", ans);

	}


	return 0;
}







































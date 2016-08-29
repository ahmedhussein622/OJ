#include <bits/stdc++.h>


using namespace std;

int n, a, b, c;
long long  w[200], d[200];
bool inc[200];
long long f = INT_MAX;
vector<vector<int>> adj;

void relax(int node) {

	for(int j = 0; j < adj[node].size(); j++) {
		int g = adj[node][j];
		long long dd = d[node] + w[g];
		if(dd > 0 && d[g] < dd) {
			d[g] = d[node] + w[g];
		}
	}

}

void solve(int kg) {

	for(int k = 0; k < kg; k++) {
		for(int i = 0; i < n; i++) {
			relax(i);
		}
	}

}

bool cycle() {

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < adj[i].size(); j++) {

			int g = adj[i][j];
			long long dd = d[i] + w[g];
			if(dd > 0 && d[g] < dd) {
				inc[g] = 1;
				inc[i] = 1;
			}

		}
	}

	bool ans = false;
	for(int i = 0; i < n; i++) {
		if(inc[i]) {
			d[i] = f;
			ans = true;
//			printf("in cycle %d\n", i);
		}

	}

	return ans;
}


int main() {


//	freopen("input.txt", "r", stdin);



	while(scanf("%d", &n) && n != -1) {

		adj.clear();

		for(int i = 0; i < n; i++) {
			d[i] = -f;
			inc[i] = 0;
			adj.push_back(vector<int> ());
			scanf("%lld", w + i);
			scanf("%d", &a);
			for(int j = 0; j < a; j++) {
				scanf("%d", &b);
				adj[i].push_back(--b);
			}
		}

		d[0] = 100;
		relax(0);
		d[0] = 0;

		solve(n - 1);



		if(cycle())
			solve(n);

		if(d[n - 1] > 0) {
			printf("winnable\n");
		}
		else {
			printf("hopeless\n");
		}

//		for(int kk = 0; kk < n; kk++) {
//			printf("%lld ", d[kk]);
//		}
//		printf("\n");
//
//
//
//		for(int kk = 0; kk < n; kk++) {
//			printf("%d ", inc[kk]);
//		}
//		printf("\n");



//		printf("%lld\n", d[n - 1]);


	}







	return 0;
}







































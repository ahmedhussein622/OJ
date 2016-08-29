#include <bits/stdc++.h>


using namespace std;


int main() {


//	freopen("input.txt", "r", stdin);


	int tc;
	scanf("%d", &tc);
	int ar[1000][1000];
	int d[1000][1000];


	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};


//	printf("here\n");

	while(tc--) {



		int n, m;
		scanf("%d", &n);
		scanf("%d", &m);



		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &ar[i][j]);
				d[i][j] = INT_MAX;
			}
		}



		priority_queue<pair<int, pair<int, int>>> q;

		d[0][0] = ar[0][0];
		q.push(make_pair(-ar[0][0], make_pair(0, 0)));


		while(!q.empty()) {
			auto p = q.top();
			q.pop();

			int x = p.second.first;
			int y = p.second.second;
			if(x == n - 1 && y == m - 1)
				break;
			int dd = -p.first;
			if(dd == d[x][y]) {
//				d[x][y] = dd;

				for(int i = 0; i < 4; i++) {
					int x2 = x + dx[i];
					int y2 = y + dy[i];
					int d2 = dd + ar[x2][y2];
					if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m &&
							d[x2][y2] > d2) {

						d[x2][y2] = d2;
						q.push(make_pair(-d2, make_pair(x2, y2)));
					}
				}
			}
		}



		printf("%d\n", d[n - 1][m - 1]);
	}


	return 0;
}







































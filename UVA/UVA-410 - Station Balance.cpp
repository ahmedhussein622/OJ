#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);


	int c, n, a, b;

	int tc = 1;
	while(scanf("%d %d", &c, &n) != EOF) {

		vector<int> v;

		int ii = 0;
		double sum = 0;
		while(ii < n) {
			scanf("%d", &a);
			v.push_back(a);
			sum += a;
			ii++;
		}
		sum /= c;

		while(ii < 2 * c) {
			v.push_back(0);
			ii++;
		}

		sort(v.begin(), v.end());


		vector<int> ar[c];


		double unp = 0;
		for(int i = 0; i < c; i++) {
			int cmp = 2 * c - i - 1;
			ar[i].push_back(v[i]);
			ar[i].push_back(v[cmp]);
			unp += abs(sum - v[i] - v[cmp]);
		}

		printf("Set #%d\n", tc++);

		for(int i = 0; i < c; i++) {
			printf(" %d:", i);
			for(int j = 0; j < ar[i].size(); j++) {
				if(ar[i][j] != 0)
					printf(" %d", ar[i][j]);
			}
			printf("\n");
		}

//		printf("%lf\n", sum);
		printf("IMBALANCE = %.5lf\n\n", unp);


	}




	return 0;
}

































#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt","r", stdin);



	long long int b[3][3];
	char cc[] = {'B', 'C', 'G'};

	while(scanf("%lld", & b[0][0]) != EOF) {

		scanf("%lld %lld", & b[0][2], & b[0][1]);
		scanf("%lld %lld %lld", & b[1][0],  & b[1][2], & b[1][1]);
		scanf("%lld %lld %lld", & b[2][0], & b[2][2], & b[2][1]);

//		 brown, clear, green

		long long int ans = 1000000000000000L;
		int a1, a2, a3;

		for(int i = 0; i < 3; i++) {

			for(int j = 0; j < 3; j++) {
				if(i == j)
					continue;

				for(int k = 0; k < 3; k++) {
					if(k == i || k == j)
						continue;
					long long int cost = b[1][i] + b[2][i];
					cost += b[0][j] + b[2][j];
					cost += b[0][k] + b[1][k];
//					printf("%c%c%c %lld %lld\n",cc[i], cc[j], cc[k], cost, ans);
					if(cost < ans) {
						ans = cost;
						a1 = i;
						a2 = j;
						a3 = k;
					}
				}
			}
		}

		printf("%c%c%c %d\n", cc[a1], cc[a2], cc[a3], ans);


	}


	return 0;
}













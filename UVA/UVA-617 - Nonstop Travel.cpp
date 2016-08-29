#include<stack>
#include <bits/stdc++.h>
using namespace std;




int main() {

//	freopen("input.txt", "r", stdin);

	int n;
	int g[10], y[10], r[10], c[10], e[10];
	double l[10];

	int cc = 1;
	while(true) {
		scanf("%d", &n);
		if(n == -1)
			break;

		for(int i = 0; i < n; i++) {
			scanf("%lf %d %d %d", l+i, g+i, y+i, r+i);
			e[i] = g[i] + y[i];
			c[i] = e[i] + r[i];
		}



		vector<int> s;

		for(int i = 30; i < 61; i++) {

			double p = i / (60.0 * 60);

			bool q = true;


			for(int j = 0; j < n && q; j++) {
				double t = l[j] / p;

				t -= c[j] * ((int)(t / c[j]));
				if(t > e[j])
					q = false;
			}

			if(q)
				s.push_back(i);

		}

		s.push_back(-1);
//		for(int i = 0; i < s.size() - 1; i++) {
//			printf("%d ", s[i]);
//		}

		printf("Case %d: ", cc++);

		for(int i = 0; i < s.size() - 1; i++) {
			if(i != 0)
				printf(", ");
			int j = i;
			while(s[j] + 1 == s[j + 1])j++;
			if(i == j)
				printf("%d", s[i]);
			else {
				printf("%d-%d", s[i], s[j]);
				i = j;
			}
		}

		if(s.size() == 1) {
			printf("No acceptable speeds.");
		}
		printf("\n");

	}

	return 0;
}





















#include<stack>
#include <bits/stdc++.h>
using namespace std;

int t, n;

int a[13], r[13], taken[20];
int cc;

void solve(int indx, int sum, int f) {
	if(indx == n) {
		if(sum == t) {
			printf("%d", taken[0]);
			for(int i = 1; i < f; i++)
				printf("+%d", taken[i]);
			printf("\n");
			cc++;
		}
	}
	else {

		sum += r[indx] * a[indx];
		for(int i = 0; i < r[indx]; i++)
			taken[f++] = a[indx];

		for(int i = r[indx]; i >= 0; i--) {
			solve(indx + 1, sum, f);
			sum -= a[indx];
			f--;
		}


	}
}


int main() {

//	freopen("input.txt", "r", stdin);

	int b, c;

	while(scanf("%d %d", &t, &n) && n) {

		memset(r, 0, sizeof(r));
		scanf("%d", a);
		r[0] = 1;

		c = 0;
		for(int i = 1; i < n; i++) {
			scanf("%d", &b);
			if(b == a[c])
				r[c]++;
			else {
				c++;
				a[c] = b;
				r[c] = 1;
			}
		}
		n = c + 1;

		printf("Sums of %d:\n", t);
		cc = 0;
		solve(0, 0, 0);
		if(cc == 0) {
			printf("NONE\n");
		}
	}

	return 0;
}
































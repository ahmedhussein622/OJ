#include <bits/stdc++.h>


using namespace std;

int n;
int ar[100010];


int fun(int k) {
	int d;
	for(int i = 1; i <= n; i++) {
		d = ar[i] - ar[i - 1];
		if(k < d)
			return -1;
		if(k == d)
			k--;
	}

	return 1;
}



int main() {


//	freopen("input.txt", "r", stdin);


	int tc;
	scanf("%d", &tc);
	ar[0] = 0;
	for(int cc = 1; cc <= tc; cc++) {
		scanf("%d", &n);
		int h = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", ar + i);
//			printf("%d\n", ar[i] - ar[i - 1]);
			h += ar[i] - ar[i - 1];
		}

		int l = 0;


		while(l + 1 != h) {

			int d = (l + h) / 2;

//			printf("%d %d %d %d\n", l, h, d, fun(d));

			if(fun(d) == 1)
				h = d;
			else
				l = d;
		}

		printf("Case %d: %d\n", cc, h);
//		printf("fun %d", fun(h));
	}

	return 0;
}

































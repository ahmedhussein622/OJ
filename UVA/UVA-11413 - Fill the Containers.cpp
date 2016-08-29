#include <bits/stdc++.h>


using namespace std;

int n, m;
int ar[1001];

int fill(int c)	{

	int k = 0;
	int i = 0;
	int f = 0;
	while(i < n && k < m) {
		if(f + ar[i] <= c) {
			f += ar[i];
			i++;
		}
		else {
			f = 0;
			k++;
		}

	}

	return i == n;
}


int main() {


//	freopen("input.txt", "r", stdin);

	while(scanf("%d %d", &n, &m) != EOF) {
		int h = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", ar + i);
			h += ar[i];
		}

		int l = 0;

		while(l + 1 != h) {
			int mid = (l + h) / 2;
			if(fill(mid))
				h = mid;
			else
				l = mid;
		}
		printf("%d\n", h);

	}

	return 0;
}

































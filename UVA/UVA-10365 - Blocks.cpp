#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		int ans = 1<<25;

		for(int i = 1; i * i <= x; i++) {
			if(x % i != 0)
				continue;
			int y = x / i;
			for(int j = 1; j * j <= y; j++) {
				if(y % j != 0)
					continue;
				int k = y / j;
				ans = min(ans, 2 * i * j + 2 * i * k + 2 * j * k);
			}

		}
		printf("%d\n", ans);
	}


	return 0;
}

































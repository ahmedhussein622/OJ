#include<stack>
#include <bits/stdc++.h>
using namespace std;




int main() {

//	freopen("input.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	while(t-- != 0) {

		int c;
		scanf("%d", &c);
		int x[c];
		for(int i = 0; i < c; i++) {
			scanf("%d", x + i);
		}

		int ans = - 1000000000;
		int mn = x[c-1];
		for(int i = c - 2; i > -1; i--) {
			if(x[i] - mn > ans)
				ans = x[i] - mn;
			mn = min(mn, x[i]);
		}
		printf("%d\n", ans);

	}

	return 0;
}





















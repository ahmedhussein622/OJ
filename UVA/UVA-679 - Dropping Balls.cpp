#include<stack>
#include <bits/stdc++.h>
using namespace std;





int main() {

//	freopen("input.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	int d, n;
	while(t--) {
		scanf("%d %d", &d, &n);

		int ans = 1;
		for(int i = 1; i < d; i++) {
			ans = ans * 2 + (n % 2 == 0);
			n = n / 2 + n % 2;
		}
		printf("%d\n", ans);

	}

	return 0;
}






















































#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int n, a, b, c, m;
	while(scanf("%d", &n) && n) {
		int ans = 0;
		int sum = 0;
		for(int i = 0; i < n;i++) {
			scanf("%d", &a);
			sum = max(a + sum, 0);
			ans = max(ans, sum);

		}

		if(ans != 0) {
			printf("The maximum winning streak is %d.\n", ans);
		}
		else {
			printf("Losing streak.\n");
		}

	}


	return 0;
}





































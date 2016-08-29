#include<stack>
#include <bits/stdc++.h>
using namespace std;




int main() {

//	freopen("input.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	while(t-- != 0) {
		int n;
		scanf("%d", &n);
		int b[n];
		scanf("%d", b);
		int ans = 0;
		for(int i = 1;i < n; i++) {
			scanf("%d", b + i);
			for(int j = 0; j < i; j++) {
				if(b[j] <= b[i])
					ans++;
			}
		}

		printf("%d\n", ans);
	}



	return 0;
}





















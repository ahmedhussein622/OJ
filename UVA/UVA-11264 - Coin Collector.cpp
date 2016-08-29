#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);

	int a, b, m, n;
	while(tc--) {

		scanf("%d", &n);
		vector<int> v;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			v.push_back(a);
		}

//		1000000000

		if(n == 1) {
			printf("1\n");
			continue;
		}


		int ans = 0;
		int sum = 0;

		for(int i = 0; i < v.size() - 1; i++) {
			if(sum + v[i] < v[i + 1]) {
//					printf("%d ", v[i]);
				sum += v[i];
				ans++;
			}
//				else if(v[i] == sum)
//					break;
		}
//			printf(" ans %d %d\n", sum, tmp);


		ans++;

		printf("%d\n", ans);

	}




	return 0;
}

































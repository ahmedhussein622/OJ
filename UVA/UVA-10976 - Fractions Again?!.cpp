#include<stack>
#include <bits/stdc++.h>
using namespace std;




int main() {

//	freopen("input.txt", "r", stdin);

	int k, a, x, y;

	while(scanf("%d", &k) != EOF) {
		vector<int> aa;
		vector<int> bb;


		for(y = k + 1; y <= 2 * k; y++) {
			if((y * k) % (y - k) == 0) {
				bb.push_back(y);
				aa.push_back((y * k) / (y - k));
			}
		}


		a = aa.size();
		printf("%d\n", a);
		for(int i = 0; i < a; i++) {
			printf("1/%d = 1/%d + 1/%d\n", k, aa[i], bb[i]);
		}



	}

	return 0;
}





















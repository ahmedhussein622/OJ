#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int n, a, b;
	while(scanf("%d", &n) && n) {

		vector<pair<int, int>> v;

		for(int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}


		sort(v.begin(), v.end());

		int l[n + 1];
		int ln = 0;

		for(int i = 0; i < n; i++) {

			int indx = lower_bound(l + 1, l + 1 + ln, v[i].second + 1) - l - 1;

			int nl = indx + 1;

			if(nl > ln || l[nl] > v[i].second) {
				l[nl] = v[i].second;
			}
			ln = max(ln, nl);

		}

		printf("%d\n", ln);



	}


	printf("*\n");

	return 0;
}





































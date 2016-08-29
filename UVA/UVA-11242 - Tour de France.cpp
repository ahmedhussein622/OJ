#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int f, r, a;
	while (true) {
		scanf("%d %d", &f, &r);

		if(f == 0)
			break;

		vector<int> fr, re;
		for (int i = 0; i < f; i++) {
			scanf("%d", &a);
			fr.push_back(a);
		}
		for (int i = 0; i < r; i++) {
			scanf("%d", &a);
			re.push_back(a);
		}


		vector<double> v;
		for (int i = 0; i < f; i++) {
			for(int j = 0; j < r; j++) {
				v.push_back((double)re[j] / fr[i]);
			}
		}


		sort(v.begin(), v.end());
		double ans = 0;

		for(int i = 0; i < v.size() - 1; i++) {
			if(v[i + 1] / v[i] > ans) {
				ans = v[i + 1] / v[i] ;
			}
		}

		ans = round(ans * 100) / 100;
		printf("%.2lf\n", ans);

	}
	return 0;
}










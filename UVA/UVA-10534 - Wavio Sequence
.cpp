#include <bits/stdc++.h>


using namespace std;

int l[10010];
int k1[10010];
int k2[10010];


void LIS(vector<int> v, int k[]) {
	int n = v.size();
	int ln = 0;

	for(int i = 0; i < n; i++) {
		int indx = lower_bound(l + 1, l + 1 + ln, v[i]) - l - 1;
		int nl = indx + 1;
		k[i] = nl;
		if(nl > ln || l[nl] > v[i]) {
			l[nl] = v[i];
		}
		ln = max(ln, nl);
	}

}



int main() {


//	freopen("input.txt", "r", stdin);

	int n, a;

	while(scanf("%d", &n) != EOF) {
		vector<int> v;

		for(int i = 0; i < n; i++) {
			scanf("%d", &a);
			v.push_back(a);
		}



		LIS(v, k1);
		reverse(v.begin(), v.end());
		LIS(v, k2);
		reverse(k2, k2 + n);

		int ans = 1;

		for(int i = 0; i < n; i++) {
			ans = max(ans, min(k1[i], k2[i])*2 - 1);
		}
		printf("%d\n", ans);


	}

	return 0;
}





































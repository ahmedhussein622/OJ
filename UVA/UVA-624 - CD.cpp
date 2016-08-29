#include<stack>
#include <bits/stdc++.h>
using namespace std;



int l, n;
int a[20];

int taken[20];
int ans;
vector<int> mAns;

void solve(int indx, int sum, int f) {
//	printf("%d %d %d\n", indx, sum ,f);
	if(indx == n) {
		if(sum > ans) {
			ans = sum;
			mAns = vector<int>(taken, taken+f);
		}
		return;
	}

	solve(indx + 1, sum, f);
	if(a[indx] <= l - sum) {
		taken[f] = a[indx];
		f++;
		solve(indx + 1, sum + a[indx], f);
		f--;
	}
}

int main() {

//	freopen("input.txt", "r", stdin);


	while(scanf("%d", &l) != EOF) {

		scanf("%d", &n);

		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		ans = 0;
		solve(0, 0, 0);

		for(int i = 0; i < mAns.size(); i++) {
			printf("%d ", mAns[i]);
		}
		printf("sum:%d\n", ans);

	}



	return 0;
}
































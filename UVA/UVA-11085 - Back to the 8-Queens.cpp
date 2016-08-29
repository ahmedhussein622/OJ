#include<stack>
#include <bits/stdc++.h>
using namespace std;

int a[8];

vector<vector<int>> v;

void queens(int indx) {
	if(indx == 8) {
		vector<int> r(a, a + 8);
		v.push_back(r);
	}

	else {
		for(int r = 0; r < 8; r++) {
			bool b = true;
			for(int i = 0; i < indx; i++) {
				if(r == a[i] || indx - i == abs(r - a[i])) {
					b = false;
				}
			}
			if(b) {
				a[indx] = r;
				queens(indx + 1);
			}
		}
	}


}



int main() {

//	freopen("input.txt", "r", stdin);


	queens(0);

	int b[8];
	int c = 1;
	while(scanf("%d", b) != EOF) {
		for(int i = 1; i < 8; i++)
			scanf("%d", b + i);
		for(int j = 0; j < 8; j++)
			b[j]--;
		int ans = 1<<25;
		for(int i = 0; i < v.size(); i++) {
			int t = 0;
			for(int j = 0; j < 8; j++) {
				t += b[j] != v[i][j];
			}

			ans = min(ans, t);
		}

		printf("Case %d: %d\n", c++, ans);
	}

	return 0;
}
































#include<stack>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int a[8];
int m[8][8];

void queens(int l) {
	if(l == 8) {
		vector<int> r;
		for(int i = 0; i < 8; i++)
			r.push_back(a[i]);
		v.push_back(r);
	}
	else {
		for(int i = 0; i < 8; i++) {
			bool b = true;
			for(int j = 0; j < l; j++) {
				if(a[j] == i || abs(l - j) == abs(i  - a[j])) {
					b = false;
					break;
				}
			}
			if(b) {
				a[l] = i;
				queens(l + 1);
			}
		}
	}
}

int main() {

//	freopen("input.txt", "r", stdin);

	queens(0);
	int s = v.size();

	int t;
	scanf("%d", &t);
	while(t--) {
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				scanf("%d", &m[i][j]);
			}
		}

		int ans = 0;

		for(int i = 0; i < s; i++) {
			int f = 0;
			for(int j = 0; j < 8; j++) {
				f += m[v[i][j]][j];
			}
			ans = max(ans, f);
		}

		printf("%5d\n", ans);

	}




	return 0;
}






























#include<stack>
#include <bits/stdc++.h>
using namespace std;

bool p[100];

void gen() {
	for(int i = 0; i < 100; i++) {
		p[i] = 1;
	}
	p[0] = p[1] = 0;
	for(int i = 2; i < 100; i++) {
		if(p[i])
			for(int j = i * i; j < 100; j += i) {
				p[j] = 0;
			}
	}


}

int n;
int a[16], t[17];

void solve(int indx) {
//	printf("%d\n", indx);
	if(indx == n) {
		if(p[1 + a[n -1]]) {
			printf("1");
			for(int i = 1; i < n; i++) {
				printf(" %d", a[i]);
			}
			printf("\n");
		}
	}
	else {
		for(int i = 2; i <= n; i++) {
			if(t[i] == 0 && p[i + a[indx - 1]]) {
				t[i] = 1;
				a[indx] = i;
				solve(indx + 1);
				t[i] = 0;
			}
		}
	}

}

int main() {

//	freopen("input.txt", "r", stdin);

	gen();
	a[0] = 1;

	int c = 1;
	while(scanf("%d", &n) != EOF) {
		memset(t, 0, sizeof(t));
		if(c != 1)
			printf("\n");
		printf("Case %d:\n", c++);
		solve(1);
	}


	return 0;
}
































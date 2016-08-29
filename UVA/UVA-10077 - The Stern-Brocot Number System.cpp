#include<stack>
#include <bits/stdc++.h>
using namespace std;





int main() {

//	freopen("input.txt", "r", stdin);

	int m, n;

	while(scanf("%d %d", &m, &n) && (m != 1 || n != 1)) {
		int la = 0;
		int lb = 1;

		int ra = 1;
		int rb = 0;

		int a, b;
		double d = (double)m / n;
		while(true) {
			a = la + ra;
			b = lb + rb;
			if(a == m && b == n)
				break;
			if(d < (double)a / b) {
				ra = a;
				rb = b;
				printf("L");
			}
			else {
				la = a;
				lb = b;
				printf("R");
			}
		}
		printf("\n");

	}

	return 0;
}






















































#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int n;
	scanf("%d", &n);

	int a, b, c, x, y, z, g, h, f;
	while(n--) {
		scanf("%d %d %d", &a, &b, &c);

		x = -10000;
		while(x <= 10000) {

			if(2 * x * x * x - 2 * a * x * x + (a * a - c) * x - 2 * b == 0 && b % x == 0) {
				g = a - x;
				h = b / x;

				if(g > 0 && g * g >= 4 * h) {
					f = g * g - 4 * h;
					f = sqrt(f);

					if(g > f)
						y = (g - f) / 2;
					else
						y = (g + f) / 2;
					z = a - x - y;
					if(x != y && x != z && y!= z)
						break;
//					if()
				}
			}

			x++;
		}

		if(x  > 10000) {
			printf("No solution.\n");
		}
		else {
			int r[3];
			r[0] = x;
			r[1] = y;
			r[2] = z;
			sort(r, r + 3);
			printf("%d %d %d\n", r[0], r[1], r[2]);
		}

	}


	return 0;
}

































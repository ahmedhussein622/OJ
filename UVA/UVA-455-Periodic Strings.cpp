#include<bits/stdc++.h>
using namespace std;



int main() {

//	freopen("input.txt", "r", stdin);

	char p[200];
	int b[200];
	int cc;
	scanf("%d", &cc);

	while (cc--) {
		scanf("%s", p);
		int m = strlen(p);

		b[0] = 0;
		int k = 0;
		for(int i = 1; i < m; i++) {
			while(k > 0 && p[k] != p[i])
				k = b[k - 1];

			k += (p[k] == p[i]);
			b[i] = k;
		}

		if(m % (m - b[m - 1]) == 0) {
			printf("%d\n", m - b[m - 1]);
		}
		else {
			printf("%d\n", m);
		}

		if(cc)
			printf("\n");

	}

	return 0;
}

































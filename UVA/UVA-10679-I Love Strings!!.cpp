#include<bits/stdc++.h>
using namespace std;



int main() {

//	freopen("input.txt", "r", stdin);


	int t, q, k, n, m;
	scanf("%d", &t);
	char s[100100], p[2000];
	int b[100100];

	while(t--) {
		scanf("%s", s);
		n = strlen(s);
		scanf("%d", &q);

		while(q--) {
			scanf("%s", p);
			m = strlen(p);

			k = b[1] = 0;
			for(int i = 1; i < m; i++) {
				while(k > 0 && p[k] != p[i])
					k = b[k];
				k += (p[k] == p[i]);
				b[i + 1] = k;
			}

			bool f = false;
			k = 0;
			for(int i = 0; i < n; i++) {
				while(k > 0 && p[k] != s[i])
					k = b[k];
				k += (p[k] == s[i]);
				if(k == m) {
					f = true;
					break;
				}
			}

			if(f) {
				printf("y\n");
			}
			else {
				printf("n\n");
			}

		}
	}

	return 0;
}

































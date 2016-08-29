#include <bits/stdc++.h>


using namespace std;
char t[1000];
char p[1000];
int b[1000];







int main() {


//	freopen("input.txt", "r", stdin);


	int tc;
	scanf("%d", &tc);

	while(tc--) {
		scanf("%s", p);
		int m = strlen(p);
		int n = m * 2;
		memcpy(t, p, m);
		memcpy(t + m, p, m);

		int j = -1;
		b[0] = -1;
		for(int i = 1; i < m; i++) {
			while(j >= 0 && p[j + 1] != p[i]) j = b[j];//while failing
			j += (p[j + 1] == p[i]);
			b[i] = j;
		}

		j = -1;
		for(int i = 1; i < n; i++) {
			while(j >= 0 && p[j + 1] != t[i]) j = b[j];
			j += (p[j + 1] == t[i]);
			if(j + 1 == m) {
				printf("%d\n", i - m + 1);
				break;
			}
		}
		if(tc != 0)
			printf("\n");

	}

	return 0;
}



























































#include <bits/stdc++.h>


using namespace std;
char p[2000100];
int b[1000100];







int main() {


//	freopen("input.txt", "r", stdin);


	while(1) {
		scanf("%s", p);
		int m = strlen(p);
		if(m == 1 &&  p[0] == '.')
			break;


		memcpy(p + m, p, m);
		int j = -1;
		b[0] = -1;

		for(int i = 1; i < m; i++) {
			while(j >= 0 && p[j + 1] != p[i]) j = b[j];
			j += p[j + 1] == p[i];
			b[i] = j;
		}


//		printf("%s\n", p);
		j = -1;
		for(int i = 1; i < m * 2; i++) {
//			printf("%d %d %c %c\n", i, j, p[i], p[j + 1]);
			while(j >= 0 && p[j + 1] != p[i]) j = b[j];
			j += p[j + 1] == p[i];

			if(j + 1 == m) {
				printf("%d\n", m / (i - m + 1));
				break;
			}
		}



	}
	return 0;
}



























































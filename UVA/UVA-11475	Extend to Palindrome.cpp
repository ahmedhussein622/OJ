#include<bits/stdc++.h>
using namespace std;



int main() {

//	freopen("input.txt", "r", stdin);

	char s1[100100], s2[100100];
	int b[100100];

	while(scanf("%s", s1) != EOF) {
		int m = strlen(s1);
		for(int i = 0; i < m; i++) {
			s2[m - i - 1] = s1[i];
		}

		int k = b[1] = 0;
		for(int i = 1; i < m; i++) {
			while(k > 0 && s2[k] != s2[i])
				k = b[k];
			k += (s2[k] == s2[i]);
			b[i + 1] = k;
		}

		k = 0;
		for(int i = 0; i < m; i++) {
			while(k > 0 && s2[k] != s1[i])
				k = b[k];
			k += (s2[k] == s1[i]);
		}

		for(int i = 0; i < m; i++)
			printf("%c", s1[i]);
		for(int i = k; i < m; i++)
			printf("%c", s2[i]);
		printf("\n");

	}

	return 0;
}

































#include<bits/stdc++.h>
using namespace std;



int main() {

//	freopen("input.txt", "r", stdin);

	char s1[1000100];
	int b[1000100];

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s1);
		int n = strlen(s1);
//		for(int i = 0; i < n; i++) {
//			s2[n - i - 1] = s1[i];
//		}

		int k = b[1] = 0;
		int i = 1;

		while(i < n) {
			while(k > 0 && s1[k] != s1[i])
				k = b[k];
			k += (s1[k] == s1[i]);
			i++;
			b[i] = k;
		}

		int ans = 0;
		i = n - 1;
		k = 0;
		while(i >= 0) {
			while(k > 0 && s1[i] != s1[k])
				k = b[k];
			k += (s1[k] == s1[i]);
			ans = max(ans, k);
			i--;
		}

		for(i = ans - 1; i >= 0; i--) {
			printf("%c", s1[i]);
		}
		printf("\n");

	}


	return 0;
}

































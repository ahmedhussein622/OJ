#include<bits/stdc++.h>
using namespace std;



int main() {

//	freopen("input.txt", "r", stdin);

	char s[1000100];
	int b[1000100];

	while(1) {
		scanf("%s", s);
		int m = strlen(s);
		if(m == 1 && s[0] == '.')
			break;

		int k = b[1] = 0;
		for(int i = 1; i < m; i++) {
			while(k > 0 && s[k] != s[i])
				k = b[k];
			k += (s[k] == s[i]);
			b[i + 1] = k;
		}

		if(m % (m - b[m]) == 0) {
			printf("%d\n", m / (m - b[m]));
		}
		else {
			printf("%d\n", 1);
		}
	}


	return 0;
}

































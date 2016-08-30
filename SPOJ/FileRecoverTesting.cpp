#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	long long n;
	int m;
	char s[1000100];
	int b[1000100];
 
	while(1) {
		scanf("%lld %s", &n, s);
		m = strlen(s);
		if(n == -1 && m == 1 && s[0] == '*')
			break;
 
//		printf("%lld %s\n", n, s);
		if(n < m) {
			printf("0\n");
			continue;
		}
 
		int k = b[1] = 0;
		for(int i = 1; i < m; i++) {
			while(k > 0 && s[i] != s[k])
				k = b[k];
			k += (s[i] == s[k]);
			b[i + 1] = k;
		}
 
		long long ans = 1 + (n - m) / (m - b[m]);
 
		printf("%lld\n", ans);
	}
 
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

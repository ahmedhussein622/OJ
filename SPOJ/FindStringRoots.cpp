#include<bits/stdc++.h>
using namespace std;
 
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	char s[100100];
	int b[100100];
 
	while(1) {
 
		scanf("%s", s);
		int n = strlen(s);
 
 
 
		if(n == 1 && s[0] == '*')
			break;
 
 
 
		int k = b[1] = 0;
		for(int i = 1; i < n; i++) {
			while(k > 0 && s[k] != s[i])
				k = b[k];
			k += (s[k] == s[i]);
			b[i + 1] = k;
		}
 
 
		if(n % (n - b[n]) == 0) {
			printf("%d\n", n / (n - b[n]));
		}
		else {
			printf("1\n");
		}
 
 
 
	}
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


#include<bits/stdc++.h>
using namespace std;
 
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	char s[1000100];
	int b[1000100];
 
	int t, n, k, i;
	scanf("%d", &t);
 
	for(int cc = 1; cc <= t; cc++) {
		printf("Test case #%d\n", cc);
		scanf("%d", &n);
		scanf("%s", s);
 
		k = b[1] = 0;
		i = 1;
		while(i < n) {
			while(k > 0 && s[k] != s[i])
				k = b[k];
			k += (s[k] == s[i]);
 
			i++;
			b[i] = k;
//			printf("%d %d\n", i, k);
			if(i % (i - k) == 0 && k > 0) {
				printf("%d %d\n", i, i / (i - k));
			}
 
		}
 
		printf("\n");
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

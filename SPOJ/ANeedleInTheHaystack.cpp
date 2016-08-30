#include<bits/stdc++.h>
using namespace std;
 
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	int n;
	int cc = 0;
	while(scanf("%d", &n) != EOF) {
		char p[n + 1];
		scanf("%s", p);
		int b[n + 1];
 
		int k = b[1] = 0;
		int i = 1;
		while(i < n) {
			while(k > 0 && p[k] != p[i])
				k = b[k];
			k += (p[k] == p[i]);
			i++;
			b[i] = k;
		}
 
 
		if(cc != 0)
			printf("\n");
 
		char c;
		k = 0;
		i = 0;
		scanf("%c", &c);
		while(scanf("%c", &c) && c != '\n') {
			while(k > 0 && p[k] != c)
				k = b[k];
			k += (p[k] == c);
			if(k == n) {
				printf("%d\n", i - k + 1);
			}
			i++;
		}
		cc++;
	}
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include<stack>
#include <bits/stdc++.h>
using namespace std;





int main() {

//	freopen("input.txt", "r", stdin);


	int t;
	scanf("%d", &t);
	int a, b;
	while(t--) {
		scanf("%d %d", &a, &b);
		char c[a + 1];
		c[a] = '\0';

		int f = b;
		for(int i = 0;i < a; i++)
			c[i] = '0';
		for(int i = a - 1; f != 0; i--, f--) {
			c[i] = '1';
		}

		do {
			printf("%s\n", c);
		}while(next_permutation(c, c + a));
		if(t != 0)
			printf("\n");
	}


	return 0;
}
































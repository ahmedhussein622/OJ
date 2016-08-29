#include<stack>
#include <bits/stdc++.h>
using namespace std;




int main() {

//	freopen("input.txt", "r", stdin);


	char a[] = "0123456789";
	char a1[6], a2[6];
	a1[5] = a2[5] = '\0';

	vector<string> b1[100];
	vector<string> b2[100];


	int c1, c2, c;
	do{

		memcpy(a1, a, 5);
		memcpy(a2, a + 5, 5);

		c1 = atoi(a1);
		c2 = atoi(a2);

		if(c1 % c2 == 0) {
			c = c1/c2;
			b1[c].push_back(string(a1));
			b2[c].push_back(string(a2));
		}

	}while(next_permutation(a, a + 10));


	bool rr = false;
	while(scanf("%d", &c) && c) {
		if(rr) {
			printf("\n");
		}
		rr = true;
		if(b1[c].size() == 0) {
			printf("There are no solutions for %d.\n", c);
		}
		else {
			for(int i = 0;i  < b1[c].size(); i++) {
				printf("%s / %s = %d\n", &b1[c][i][0], &b2[c][i][0], c);
			}
		}

	}

	return 0;
}





















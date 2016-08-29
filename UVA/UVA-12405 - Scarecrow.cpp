#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int a, b, c, n, m;
	int tc;
	scanf("%d", &tc);

	char s[200];
	for(int cc = 1; cc <= tc; cc++) {

		scanf("%d", &n);
		scanf("%s", s);

		int ans = 0;

		c = 0;


		while(c < n) {
			while(c < n && s[c] == '#')
				c++;
			if(c < n) {
				ans++;
				c += 3;
			}
		}


		printf("Case %d: %d\n", cc, ans);


	}


	return 0;
}





































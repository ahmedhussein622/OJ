#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int n, c;
	while(scanf("%d", &n) != EOF) {
		vector<int> a, b;

		for(int i = 0; i < n; i++) {
			scanf("%d", & c);
			a.push_back(c);
		}

		for(int i = 0; i < n; i++) {
			scanf("%d", & c);
			b.push_back(c);
		}

		int ans = 0;

		for(int i = 0; i < n; i++) {
			int k = a[i];
			int j = 0;
			set<int> s;
			for(j = 0; j < n; j++) {
				if(b[j] == k)
					break;
				s.insert(b[j]);
			}
			for(int k = 0; k < i; k++) {
				if(s.find(a[k]) == s.end())
					ans++;
			}


		}


		printf("%d\n", ans);


	}



	return 0;
}










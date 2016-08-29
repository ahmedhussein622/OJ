#include <bits/stdc++.h>


using namespace std;

int main() {


//	freopen("input.txt", "r", stdin);

	char c;
	char s[200];
	while(scanf("%c", &c) != EOF) {
		unordered_map<char, vector<int> > m;
		for(char cc = 'a'; cc <= 'z'; cc++)
			m[cc] = vector<int>();
		for(char cc = 'A'; cc <= 'Z'; cc++)
			m[cc] = vector<int>();

		m[c].push_back(0);
		int t = 1;
		while(scanf("%c", &c) && c != '\n') {
			m[c].push_back(t++);
		}

		int tc;
		scanf("%d", &tc);
		while(tc--) {
			scanf("%s", &s);
			int l = strlen(s);

			int i = 0;
			int k = 0;
			int b;
			while(i < l) {
				vector<int> v = m[s[i]];
				auto it = lower_bound(v.begin(), v.end(), k);
				if(it == v.end())
					break;
				k = *it + 1;
				if(i == 0)
					b = *it;
				i++;
			}

			if(i == l) {
				printf("Matched %d %d\n",b, k-1);
			}
			else {
				printf("Not matched\n");
			}

		}

	}

	return 0;
}






























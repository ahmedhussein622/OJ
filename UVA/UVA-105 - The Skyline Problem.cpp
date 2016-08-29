#include<stack>
#include <bits/stdc++.h>
using namespace std;




int main() {

//	freopen("input.txt", "r", stdin);


	vector<int> l, r, h;
	int a, b, c;
	set<int> s;
	s.insert(10000000);

	while(scanf("%d %d %d\n", &a, &b, &c) != EOF) {
		l.push_back(a);
		h.push_back(b);
		r.push_back(c);

		s.insert(a);
		s.insert(c);
	}



	vector<int> v(s.begin(), s.end());
	vector<int> t(v.size(), 0);

	for(int i = 0; i < s.size() - 1; i++) {
		double d = (v[i] + v[i + 1]) / 2.0;
		int m = 0;
		for(int j = 0; j < l.size(); j++) {
			if(d >= l[j] && d <= r[j]) {
				m = max(m, h[j]);
			}
		}
		t[i] = m;
//		printf("%d %lf %d \n", i, d, m);
	}

	printf("%d %d", v[0], t[0]);
	for(int i = 1; i < s.size() - 1; i++) {
		if(t[i] == t[i - 1])
			continue;

		printf(" %d %d", v[i], t[i]);
	}
	printf("\n");

	return 0;
}





















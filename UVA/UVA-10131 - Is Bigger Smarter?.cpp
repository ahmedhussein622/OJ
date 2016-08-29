#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);

	int n, a, b;
	vector<pair<int, int>> v;
	map<pair<int, int>, int> mapper;

	int kk = 1;
	while(scanf("%d %d", &a, &b) != EOF) {
		v.push_back(make_pair(-b, -a));
		mapper[make_pair(b, a)] = kk++;
	}

	sort(v.begin(), v.end());
	n = v.size();
	for(int i = 0; i < n; i++) {
		v[i].first *= -1;
		v[i].second *= -1;
	}



	int l[n + 1];
	int loc[n + 1];
	int p[n];
	int ln = 0;
	loc[0] = -1;

	for(int i = 0; i < n; i++) {

		int indx = lower_bound(l + 1, l + ln + 1, v[i].second) - l - 1;
		int nl = indx + 1;
		p[i] = loc[indx];
		if(ln < nl || l[nl] > v[i].second) {
			l[nl] = v[i].second;
			loc[nl] = i;
		}
		ln = max(ln, nl);
	}

	vector<int> ans;
	int indx = loc[ln];
	while(indx != -1) {
		ans.push_back(mapper[v[indx]]);
		indx = p[indx];
	}

	printf("%d\n", ln);

	for(int i = ans.size() - 1; i >= 0; i--) {
		printf("%d\n", ans[i]);
	}



//	printf("*\n");

	return 0;
}





































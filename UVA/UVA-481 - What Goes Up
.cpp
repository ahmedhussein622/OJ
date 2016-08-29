#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);


	int n, a, b;
	vector<int> v;
	while(scanf("%d", &a) != EOF) {
		v.push_back(a);
	}



	n = v.size();



	int ln[n + 1];
	int loc[n + 1];
	int l = 0;

	int p[n];
	loc[0] = -1;

	for(int i = 0; i < n; i++) {

//		for(int j = 1; j <= l; j++)
//			printf("%d, ", ln[j]);
//		printf("\n");
		a = v[i];
		int indx = lower_bound(ln + 1, ln + 1 + l, a) - ln - 1;

		int nl = indx + 1;
		p[i] = loc[indx];

		if((nl <= l && ln[nl] >= a) || l < nl) {
				loc[nl] = i;
				ln[nl] = a;
		}
		l = max(l, nl);

//		printf("%d %d %d %d    %d\n", i, v[i], indx, ln[indx], l);

	}

	printf("%d\n-\n", l);

	int indx = loc[l];
	vector<int> an;
	while(indx != -1) {
		an.push_back(v[indx]);
		indx = p[indx];
	}

	for(int i = an.size() - 1; i >= 0; i--) {
		printf("%d\n", an[i]);
	}


	return 0;
}





































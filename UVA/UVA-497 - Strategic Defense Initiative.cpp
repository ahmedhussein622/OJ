#include <bits/stdc++.h>


using namespace std;



int main() {


//	freopen("input.txt", "r", stdin);


	char s[100];
	int tc;
	scanf("%d\n", &tc);




	int a, b, n;
	for(int cc = 1; cc <= tc; cc++) {
		vector<int> v;


		while(gets(s) != NULL && strlen(s) != 0) {

			sscanf(s, "%d", &a);
			v.push_back(a);
		}

		reverse(v.begin(), v.end());

		n = v.size();
		int l[n];
		int p[n];
		int indx = 0;
		int mx = 1;

		for(int i = 0; i < n; i++) {
			l[i] = 1;
			p[i] = -1;
			for(int j = 0; j < i; j++) {
				if(v[j] > v[i]) {
					if(l[i] < l[j] + 1) {
						l[i] = l[j] + 1;
						p[i] = j;
					}
				}
			}

			if(l[i] > mx) {
				mx = l[i];
				indx = i;
			}

		}

		printf("Max hits: %d\n", mx);
		while(indx != -1) {
			printf("%d\n", v[indx]);
			indx = p[indx];
		}

		if(cc != tc)
			printf("\n");


	}




	return 0;
}





































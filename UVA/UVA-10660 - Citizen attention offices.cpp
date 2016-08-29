#include<stack>
#include <bits/stdc++.h>
using namespace std;



int main() {

//	freopen("input.txt", "r", stdin);

	int t, n, a, b, c;
	scanf("%d", &t);
	for(int cc = 1; cc <= t; cc++) {
		vector<pair<int, int>> v;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			v.push_back(make_pair(a * 5 + b, c));
		}

		int ans = 1<<25;
		int ans2[5];
		for(int i_1 = 0; i_1 < 25; i_1++) {
			for(int i_2 = i_1 + 1; i_2 < 25; i_2++) {
				for(int i_3 = i_2 + 1; i_3 < 25; i_3++) {
					for(int i_4 = i_3 + 1; i_4 < 25; i_4++) {
						for(int i_5 = i_4 + 1; i_5 < 25; i_5++) {
							int k = 0;
							for(int i = 0; i < n; i++) {
								int t1 = (abs(v[i].first  / 5 - i_1 / 5) + abs(v[i].first % 5 - i_1 % 5) ) * v[i].second;
								int t2 = (abs(v[i].first  / 5 - i_2 / 5) + abs(v[i].first % 5 - i_2 % 5) ) * v[i].second;
								int t3 = (abs(v[i].first  / 5 - i_3 / 5) + abs(v[i].first % 5 - i_3 % 5) ) * v[i].second;
								int t4 = (abs(v[i].first  / 5 - i_4 / 5) + abs(v[i].first % 5 - i_4 % 5 ) ) * v[i].second;
								int t5 = (abs(v[i].first  / 5 - i_5 / 5) + abs(v[i].first % 5 - i_5 % 5 ) ) * v[i].second;
								k += min(t1, min(min(t2, t3), min(t4, t5)));
							}
							if(ans > k) {
								ans = k;
								ans2[0] = i_1;
								ans2[1] = i_2;
								ans2[2] = i_3;
								ans2[3] = i_4;
								ans2[4] = i_5;
							}
						}
					}
				}
			}
		}

		for(int i = 0; i < 5; i++) {
			if(i != 0)
				printf(" ");
			printf("%d", ans2[i]);
		}
		printf("\n");

	}

	return 0;
}














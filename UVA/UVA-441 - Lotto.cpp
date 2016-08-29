#include<stack>
#include <bits/stdc++.h>
using namespace std;

int main() {

//	freopen("input.txt", "r", stdin);

	int n;
	int k = 0;
	while(scanf("%d", &n) && n) {

		if(k != 0)
			printf("\n");
		k++;

		int a[n];
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}

		for(int i_1 = 0; i_1 < n; i_1++) {
			for(int i_2 = i_1 + 1; i_2 < n; i_2++) {
				for(int i_3 = i_2 + 1; i_3 < n; i_3++) {
					for(int i_4 = i_3 + 1; i_4 < n; i_4++) {
						for(int i_5 = i_4 + 1; i_5 < n; i_5++) {
							for(int i_6 = i_5 + 1; i_6 < n; i_6++) {
								printf("%d %d %d %d %d %d\n", a[i_1], a[i_2], a[i_3], a[i_4], a[i_5], a[i_6]);
							}
						}
					}
				}
			}
		}



	}



	return 0;
}










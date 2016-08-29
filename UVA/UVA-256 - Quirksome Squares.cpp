#include<stack>
#include <bits/stdc++.h>
using namespace std;

//vector<vector<string>> v;
//
//int a, c;
//void adder(int i, int j, int a, int d, int g) {
//	int c = (i * d + j);
//	if(c < d * d && c == a) {
//		string s = to_string(c);
//		v[g].push_back(string(max(0, g - (int)s.length()), '0').append(s));
//	}
//}


int main() {

//	freopen("input.txt","r", stdin);


//	2,4,6,8

//	for(int i = 0; i < 10; i++) {
//		vector<string> k;
//		v.push_back(k);
//	}

//	int a;
//	for(int i = 0; i <= 9999; i++) {
//		for(int j = 0; j <= 9999; j++) {
//			a = (i + j);
//			a *= a;
//
//			adder(i, j, a, 10, 2);
//			adder(i, j, a, 100, 4);
//			adder(i, j, a, 1000, 6);
//			adder(i, j, a, 10000, 8);
//
//		}
//	}

//	int x;
//	while(scanf("%d", &x) != EOF) {
//		int s = v[x].size();
//		for(int i = 0; i < s; i++) {
//			printf("%s\n", & v[x][i][0]);
//		}
//	}

	char s2[] = "00\n01\n81\n";
	char s4[] = "0000\n0001\n2025\n3025\n9801\n";
	char s6[] = "000000\n000001\n088209\n494209\n998001\n";
	char s8[] = "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";

	char * ans[10];
	ans[2] = s2;
	ans[4] = s4;
	ans[6] = s6;
	ans[8] = s8;

	int x;
	while(scanf("%d", &x) != EOF) {
		printf("%s", ans[x]);
	}

	return 0;
}













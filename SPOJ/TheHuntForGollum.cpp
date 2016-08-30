#include<bits/stdc++.h>
using namespace std;
 
int n1, n2;
int m1, m2;
 
string p[310];
int pp[310];
int b[310];
 
char t[2010][2010];
 
int t2[2010][2010];
 
 
 
void prefix(char s[], int n, int b[]) {
 
	int k = b[1] = 0;
	for(int i = 1; i < n; i++) {
		while(k > 0 && s[k] != s[i])
			k = b[k];
		k += (s[k] == s[i]);
		b[i + 1] = k;
	}
 
}
 
void kmp1(char t[], int fill[], int n, char p[], int m, int b[], int v) {
 
 
	int k = 0;
	for(int i = 0; i < n; i++) {
		while(k > 0 && t[i] != p[k])
			k = b[k];
		k += (t[i] == p[k]);
		if(k == m) {
			k = b[k];
			fill[i] = v;
		}
	}
 
}
 
void horizontal() {
	memset(t2, 0, sizeof(t2));
 
	for(int i = 0; i < m1; i++) {
		char * pat = &(p[i][0]);
		prefix(pat, m2, b);
		for(int j = 0; j < n1; j++) {
			kmp1(t[j], t2[j], n2, pat, m2, b, pp[i]);
		}
	}
}
 
void vertical() {
 
	vector<pair<int, int>> ans;
 
	int k = b[1] = 0;
	for(int i = 1; i < m1; i++) {
		while(k > 0 && pp[k] != pp[i])
			k = b[k];
		k += (pp[k] == pp[i]);
		b[i + 1] = k;
	}
 
	for(int j = 0; j < n2; j++) {
		k = 0;
		for(int i = 0; i < n1; i++) {
			while(k > 0 && pp[k] != t2[i][j])
				k = b[k];
			k += (pp[k] == t2[i][j]);
			if(k == m1) {
				ans.push_back(make_pair(i - k + 2, j - m2 + 2));
				k = b[k];
			}
		}
	}
 
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		printf("(%d,%d)\n", ans[i].first, ans[i].second);
	}
 
	if(ans.size() == 0) {
		printf("NO MATCH FOUND...\n");
	}
 
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d %d", &m1, &m2);
 
	unordered_map<string, int> maper;
	int ff = 1;
	for(int i = 0; i < m1; i++) {
		cin>>p[i];
		if(maper.find(p[i]) == maper.end()) {
			maper[p[i]] = ff++;
		}
		pp[i] = maper[p[i]];
//		printf("%d\n", pp[i]);
	}
 
	scanf("%d %d", &n1, &n2);
	for(int i = 0; i < n1; i++) {
		scanf("%s", t[i]);
	}
 
	horizontal();
//	for(int i = 0; i < n1; i++) {
//		for(int j = 0; j < n2; j++) {
//			printf("%d ", t2[i][j]);
//		}
//		printf("\n");
//	}
 
	vertical();
 
 
//	printf("done\n");
 
	return 0;
}
 

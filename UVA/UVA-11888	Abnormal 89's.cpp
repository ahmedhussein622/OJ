#include<bits/stdc++.h>
using namespace std;

int n;
char t[200100], p[200100];
int b[200100];

int kmp(char t[], char p[]) {


	int k = b[1] = 0;
	for(int i = 1; i < n; i++) {
		while(k > 0 && p[k] != p[i])
			k = b[k];
		k += (p[k] == p[i]);
		b[i + 1] = k;
	}

	k = 0;
	for(int i = 0; i < n; i++) {
		while(k > 0 && t[i] != p[k])
			k = b[k];
		k += (p[k] == t[i]);
	}

	return k;
}

void solve() {

	n = strlen(t);
	memcpy(p, t, n);
	reverse(p, p + n);

	map<int, int> maper;

	int k = kmp(t, p);
	while(k > 0) {
		maper[k] = 1;
		k = b[k];
	}


	k = kmp(p, t);
	int gg = k;
	bool f = false;
	while(k > 0) {
		if(k != n) {
			if(maper[n - k] != 0) {
				f = true;
				break;
			}
		}
		k = b[k];
	}



	if(f) {
		printf("alindrome\n");
	}
	else if(gg == n) {
		printf("palindrome\n");
	}
	else {
		printf("simple\n");
	}

}


int main() {

//	freopen("input.txt", "r", stdin);

	int cc;
	scanf("%d", &cc);
	while(cc--) {
		scanf("%s", t);
		solve();
	}



	return 0;
}

































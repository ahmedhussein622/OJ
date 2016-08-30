#include<bits/stdc++.h>
using namespace std;
 
 
bool visited[1000000][26];
bool f[1000000];
int counter[1000000];
int nxt[1000000][26];
int size;
 
char s[100100];
 
bool insert() {
 
	int node = 0;
	int n = strlen(s);
 
	for(int i = 0; i < n; i++) {
		int c = s[i] - '0';
 
		if(!visited[node][c]) {
			visited[node][c] = 1;
			counter[node]++;
 
			size++;
 
			memset(visited[size], 0, 26);
			counter[size] = 0;
			f[size] = false;
			nxt[node][c] = size;
		}
 
		node = nxt[node][c];
 
		if(f[node]) {
			return false;
		}
 
	}
 
	f[node] = true;
 
	return counter[node] == 0;
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	int t;
	scanf("%d", &t);
 
	while(t--) {
		int n;
		scanf("%d", &n);
 
		size = 0;
		memset(visited[0], 0, 26);
		counter[0] = 0;
		f[0] = false;
 
		bool ans = true;
		int i;
		for(i = 0; i < n && ans; i++) {
			scanf("%s", s);
//			printf("%s\n", s);
			ans &= insert();
 
		}
 
		while(i < n) {
			scanf("%s", s);
			i++;
		}
 
		if(ans) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
 
 
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 

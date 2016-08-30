#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n =  100000;
int st[100000  * 4];
int a[100000];
int sum, used, k;
 
 
void build() {
 
	for(int i = 0; i < n; i++) {
		a[i] = k;
	}
	for(int i = 0; i < 4 * n; i++) {
			st[i] = k;
	}
	sum = used = 0;
}
 
void insert(int node, int lt, int rt, int val) {
//	printf("inserting : %d %d % d %d\n", node, lt, rt, val);
	if(lt == rt) {
		if(a[lt] == k)
			used++;
		a[lt] -= val;
		st[node] = a[lt];
		return;
	}
 
	if(st[node * 2] >= val) {
		insert(node * 2, lt, (lt + rt) / 2, val);
	}
	else {
		insert(node * 2 + 1,(lt + rt) / 2 + 1, rt, val);
	}
 
	st[node] = max(st[node * 2], st[node * 2 + 1]);
}
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	int t, m, a, b;
	scanf("%d", &t);
	char c[100];
	while(t--) {
		scanf("%d", &k);
		scanf("%d", &m);
 
		build();
		for(int i = 0; i < m; i++) {
			scanf("%s", c);
			if(c[0] == 'b') {
				scanf("%d %d", &a, &b);
 
				i += a - 1;
				sum += a * b;
 
				for(int j = 0; j < a; j++)
					insert(1,0, n-1, b);
 
			}
			else {
				sum += atoi(c);
				insert(1, 0, n-1,atoi(c));
			}
		}
 
//		printf("%d %d %d \n",sum, used, k);
		printf("%d %d\n",used, used * k - sum);
	}
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n = 100100;
int start[100100], finish[100100];
int st[100100 * 4];
 
int compine(int lt , int mid, int rt, int ansL, int ansR) {
	int ans = max(ansL, ansR);
	lt = max(lt, start[mid]);
	rt = min(rt, finish[mid]);
	ans = max(ans,rt - lt + 1);
	return ans;
}
 
 
 
void build(int node , int lt, int rt) {
	if(lt == rt) {
		st[node] = 1;
	}
	else {
		int mid = (lt + rt) / 2;
		build(node * 2, lt , mid);
		build(node * 2 + 1, mid + 1, rt);
 
		st[node] = compine(lt, mid, rt, st[node * 2], st[node * 2 + 1]);
	}
}
 
int query(int node, int lt, int rt, int lq, int rq) {
	if(lt == rt)
		return 1;
 
	if(lt  > rq || rt < lq)
		return 0;
 
	if(lt >= lq && rt <= rq)
		return st[node];
 
	int mid = (lt + rt) / 2;
	int left = query(node * 2, lt, mid, lq, rq);
	int right = query(node * 2 + 1, mid + 1, rt, lq, rq);
 
	return compine(lq, mid, rq, left, right);
}
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	int a, b, m, d;
	int input[100100];
	while(scanf("%d %d", &n, &m) && n) {
		for(int i = 0;  i < n; i++) {
			scanf("%d", input + i);
		}
 
		a = 0;
		while(a < n) {
			b = a;
			d = input[a];
			while(a < n && input[a] == d)a++;
			for(int i = b ; i < a; i++) {
				start[i] = b;
				finish[i] = a - 1;
			}
		}
 
 
 
		build(1, 0 , n - 1);
 
 
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
 
			printf("%d\n", query(1, 0, n - 1, a - 1, b - 1));
		}
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

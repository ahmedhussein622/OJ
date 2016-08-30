#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n = 100010;
int st[100010 * 4];
bool lazy[100010 * 4];
 
void build() {
	memset(st, 0, sizeof st);
	memset(lazy, 0, sizeof lazy);
}
 
 
void lazyUpdate(int node, int lt, int rt) {
	if(!lazy[node])
		return;
 
	st[node] = (rt - lt + 1	 - st[node]);
	if(lt != rt) {
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
	lazy[node] = 0;
}
 
 
void update(int node, int lt, int rt, int lq, int rq) {
 
	lazyUpdate(node, lt, rt);
 
	if(lt > rq || rt < lq)
		return;
 
	else if(lt == rt) {
		st[node] = !st[node];
		return;
	}
 
	else if(lt >= lq && rt <= rq) {
		st[node] = (rt - lt + 1	 - st[node]);
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
	else {
		update(node * 2, lt, (lt + rt) / 2, lq, rq);
		update(node * 2 + 1,(lt + rt) / 2 + 1, rt, lq, rq);
		st[node] = st[node * 2] + st[node * 2 + 1];
	}
 
}
 
int query(int node ,int lt, int rt, int lq, int rq) {
 
	lazyUpdate(node, lt, rt);
	int ans = 0;
 
	if(lt > rq || rt < lq)
			ans = 0;
 
	else if(lt == rt || (lt >= lq && rt <= rq)) {
		ans = st[node];
	}
 
	else {
		ans = query(node * 2, lt, (lt + rt) / 2, lq, rq);
		ans += query(node * 2 + 1,(lt + rt) / 2 + 1, rt, lq, rq);
	}
 
	return ans;
 
}
 
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
 
	int m, a, b, c;
	scanf("%d %d", &n, &m);
	build();
 
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		b--,c--;
		if(a == 0) {
			update(1,0, n - 1, b, c);
		}
		else {
			printf("%d\n",query(1, 0, n - 1, b, c));
		}
 
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<vector<int> > g;
int e[1000000], ed[1000000], h[1000000];
int cnt;
 
void dfs(int node, int depth) {
	h[node] = cnt;
	e[cnt] = node;
	ed[cnt++] = depth;
 
	for(int i = 0; i < (int)g[node].size(); i++) {
		dfs(g[node][i], depth + 1);
		e[cnt] = node;
		ed[cnt++] = depth;
	}
}
 
pair<int, int> st[1000000];
void compine(pair<int, int > * ans,pair<int, int > * l, pair<int, int > * r) {
	if(l->first < r->first) {
		ans->first = l->first;
		ans->second = l->second;
	}
	else {
		ans->first = r->first;
		ans->second = r->second;
	}
}
 
 
 
void build(int node, int lt, int rt) {
	if(lt == rt) {
		st[node].first = ed[lt];
		st[node].second = e[lt];
	}
	else {
		int mid = (lt + rt) / 2;
		build(node * 2, lt, mid);
		build(node * 2 + 1, mid + 1, rt);
		compine(st + node, st + node * 2, st + node * 2 + 1);
	}
}
 
void query(int node, int lt, int rt, int lq, int rq, pair<int, int> * ans) {
	if(lt > rq || rt < lq) {
		ans->first = 99999999;
	}
	else if(lt >= lq && rt <= rq) {
		ans->first = st[node].first;
		ans->second = st[node].second;
	}
	else {
		int mid = (lt + rt) / 2;
		pair<int, int> l ,r;
		query(node * 2, lt, mid, lq, rq, &l);
		query(node * 2 + 1, mid + 1, rt, lq, rq, &r);
		compine(ans, &l, &r);
	}
}
 
int lca(int a, int b) {
	pair<int, int> q;
	if(h[a] > h[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	query(1,0, cnt - 1, h[a], h[b], &q);
	return q.second;
}
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
	int t,a,b,q;
	scanf("%d", &t);
	for(int kk = 1; kk <= t; kk++) {
		scanf("%d", &n);
		g.clear();
		g.resize(n + 1);
		for(int i = 1; i <= n;i++) {
			scanf("%d", &a);
			for(int j = 0; j < a; j++) {
				scanf("%d", &b);
				g[i].push_back(b);
			}
		}
 
		scanf("%d", &q);
		cnt = 0;
		dfs(1, 0);
 
		build(1, 0, cnt - 1);
 
		printf("Case %d:\n", kk);
		for(int i = 0; i < q; i++) {
			scanf("%d %d", &a, &b);
			printf("%d\n", lca(a, b));
		}
 
 
 
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 


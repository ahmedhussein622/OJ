
#include <bits/stdc++.h>
using namespace std;
 
int n;
int e[1000000], ed[1000000], h[1000000];
long long dist[1000000];
int level[1000000];
int cnt = 0;
pair<long long, int>st[5000000];
 
vector<vector<pair<int, int> > > g;
vector<vector<int> > depths;
 
void addEular(int node, int depth) {
	e[cnt] = node;
	ed[cnt] = depth;
	depths[depth].push_back(cnt);
	cnt++;
}
 
void dfs(int node, int parent, int depth, long long d) {
	h[node] = cnt;
	dist[node] = d;
	level[node] = depth;
	addEular(node, depth);
 
	for(int i = 0; i < (int)g[node].size(); i++) {
		if(g[node][i].first == parent)
			continue;
		dfs(g[node][i].first, node, depth + 1, d + g[node][i].second);
		addEular(node, depth);
	}
}
 
void compine(pair<long long, int> *ans, pair<long long, int> *l, pair<long long, int> *r) {
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
		st[node].second = lt;
	}
	else {
		int mid = (lt + rt) / 2;
		build(node * 2, lt, mid);
		build(node * 2 + 1, mid + 1, rt);
		compine(&st[node], &st[node * 2], &st[node * 2 + 1]);
	}
}
 
void query(int node, int lt, int rt, int lq, int rq, pair<long long , int> * ans) {
	if(lt > rq || rt < lq) {
		ans->first = 9999999999;
	}
	else if(lt >= lq && rt <= rq) {
		ans->first = st[node].first;
		ans->second = st[node].second;
	}
	else {
		pair<long long, int> l, r;
		int mid = (lt + rt) / 2;
		query(node * 2, lt, mid, lq, rq, &l);
		query(node * 2 + 1, mid + 1, rt, lq, rq, &r);
		compine(ans, &l, &r);
	}
}
 
int lcaIndx(int a, int b) {
	if(h[a] > h[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	pair<long long, int> q;
	query(1, 0, cnt - 1, h[a],h[b],&q);
	return q.second;
}
 
long long getDist(int a, int b) {
	int la = lcaIndx(a, b);
	return dist[a] + dist[b] - 2 * dist[e[la]];
}
 
int getKth(int a, int b, int k) {
	int la = lcaIndx(a, b);
	int r = e[la];
	int t = level[a] + level[b] - 2 * level[r] + 1;
 
	if(h[a] > h[b]) {
		int tmp = a;
		a = b;
		b = tmp;
		k = t - k + 1;
	}
 
 
	vector<int>::iterator it;
	int d;
	if(level[a] - level[r] + 1 >= k) {
		d = level[a] - k + 1;
		it = lower_bound(depths[d].begin(), depths[d].end(), h[a]);
	}
	else {
		d = level[b] + k - t;
		it = upper_bound(depths[d].begin(), depths[d].end(), h[b]);
		it--;
	}
 
	return e[*it];
}
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	int t, a, b, c;
	scanf("%d", &t);
	char s[50];
	while(t--) {
		scanf("%d", &n);
		g.clear();
		depths.clear();
		g.resize(n);
		depths.resize(n);
		for(int i = 0; i < n - 1; i++) {
			scanf("%d %d %d", &a, &b, &c);
			g[a-1].push_back(make_pair(b - 1, c));
			g[b-1].push_back(make_pair(a - 1, c));
		}
		dfs(0, -1, 0, 0);
		build(1, 0, cnt - 1);
		while(true) {
			scanf("%s", s);
			if(s[1] == 'O')
				break;
			scanf("%d %d", &a, &b);
			a--,b--;
			if(s[0] == 'D') {
				printf("%lld\n",getDist(a, b));
			}
			else {
				scanf("%d", &c);
				printf("%d\n",getKth(a, b, c) + 1);
			}
		}
	}
 
	return 0;
}
 
 
 
 
 
 
 
 

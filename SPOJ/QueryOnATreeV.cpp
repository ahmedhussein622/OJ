#include<bits/stdc++.h>
#define MX  100200
#define LOGMX 20
using namespace std;
 
int n;
vector<vector<int> > g, cent_tree;
int sub_tree[MX], level[MX], p[MX], dp[LOGMX][MX];
bool visited[MX], black[MX];
set<pair<int, int> > ans[MX];
 
void sub_tree_size(int node, int parent) {
	sub_tree[node] = 1;
	int t;
	for(int i = 0; i < (int)g[node].size(); i++) {
		t = g[node][i];
		if(!visited[t] && t != parent) {
			sub_tree_size(t, node);
			sub_tree[node] += sub_tree[t];
		}
	}
}
 
int find_cent(int node, int parent, int s) {
 
	int mx = -1;
	int node2 = -1;
	int t;
 
	for(int i = 0; i < (int)g[node].size(); i++) {
		t = g[node][i];
		if(!visited[t] && t != parent && mx < sub_tree[t]) {
			mx = sub_tree[t];
			node2 = t;
		}
	}
 
	if(mx == -1 || mx <= s / 2)
		return node;
 
	return find_cent(node2, node, s);
 
}
 
 
void dfs(int node, int parent, int depth, int l) {
	dp[l][node] = depth;
 
	depth++;
	for(int i = 0; i <(int)g[node].size(); i++) {
		int t = g[node][i];
		if(!visited[t] && t != parent) {
			dfs(t, node, depth, l);
		}
	}
}
 
int decomposition(int node, int l, int parent) {
 
	sub_tree_size(node, -1);
	int cent = find_cent(node, -1, sub_tree[node]);
	p[cent] = parent;
	level[cent] = l;
	visited[cent] = true;
	dfs(cent, -1, 0, l);
 
 
	int t;
	l++;
 
	for(int i = 0; i < (int)g[cent].size(); i++) {
		t = g[cent][i];
		if(!visited[t]) {
			t = decomposition(t, l, cent);
			cent_tree[cent].push_back(t);
		}
	}
 
	return cent;
}
 
void update(int node) {
 
	int cent = node;
	bool c = black[node];
	black[node] = !c;
	int l;
	while(cent != -1) {
 
		l = level[cent];
		if(c) {
			ans[cent].insert(make_pair(dp[l][node], node));
		}
		else {
			auto it = ans[cent].find(make_pair(dp[l][node], node));
			ans[cent].erase(it);
		}
 
		cent = p[cent];
	}
}
 
int query(int node) {
 
	int cent = node;
	int mi = 99999999;
	int l;
	while(cent != -1) {
		l = level[cent];
		if(ans[cent].size() != 0) {
			auto it = ans[cent].begin();
			mi = min(mi , dp[l][node] + (*it).first);
		}
		cent = p[cent];
	}
 
	if(mi == 99999999)
		mi = -1;
	return mi;
}
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int a, b;
	g.resize(n + 1);
	cent_tree.resize(n + 1);
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
 
	memset(visited, 0, sizeof visited);
	memset(black, 1, sizeof black);
 
	decomposition(1, 0, -1);
 
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if(a == 0) {
			update(b);
		}
		else {
			printf("%d\n", query(b));
		}
	}
 
	return 0;
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include <bits/stdc++.h>
using namespace std;
#define LIMIT 20100
int n;
vector<vector<pair<int, int> > > adj;
vector<vector<int> > chains, st_chains;
pair<int, int> euler[LIMIT * 2];//node-depth
int chain_head[LIMIT];
int st[100000];
struct Node {
	int depth, parent, chain, indx, dist, subTree, h;
};
Node g[LIMIT];
 
int eCount;
int dfs(int node, int parent, int depth, int dist) {
	g[node].parent = parent;
	g[node].depth = depth;
	g[node].dist = dist;
	g[node].h = eCount;
 
	euler[eCount].first = node;
	euler[eCount++].second = depth;
 
	int s = 1;
	for(int i = 0;i  < (int)adj[node].size(); i++) {
		if(adj[node][i].first != parent) {
			s += dfs(adj[node][i].first, node, depth + 1, adj[node][i].second);
			euler[eCount].first = node;
			euler[eCount++].second = depth;
		}
	}
	return g[node].subTree = s;
}
 
 
int compine_euler(int a, int b) {
	if(euler[a].second < euler[b].second)
		return a;
	return b;
}
 
void build_euler(int node, int lt, int rt) {
	if(lt == rt) {
		st[node] = lt;
	}
	else {
		int mid = (lt + rt) / 2;
		build_euler(node * 2, lt, mid);
		build_euler(node * 2 + 1, mid + 1, rt);
		st[node] = compine_euler(st[node * 2], st[node * 2 + 1]);
	}
}
 
int query_euler(int node, int lt, int rt, int lq, int rq) {
	if(lt > rq || rt < lq)
		return -1;
 
	int ans;
	if(lt >= lq && rt <= rq) {
		ans = st[node];
 
	}
	else {
		int mid = (lt + rt) / 2;
		int l = query_euler(node * 2, lt, mid, lq, rq);
		int r = query_euler(node * 2 + 1, mid + 1, rt, lq, rq);
		if(l == -1)
			ans =  r;
		else if(r == -1)
			ans =  l;
		else
			ans =  compine_euler(l, r);
	}
 
	return ans;
}
 
 
void hld(int node, int c) {
	g[node].indx = chains[c].size();
	g[node].chain = c;
	chains[c].push_back(g[node].dist);
 
	int indx = -1;
	int mx = -1;
 
	for(int i = 0; i < (int)adj[node].size(); i++) {
		if(adj[node][i].first != g[node].parent) {
			if(g[adj[node][i].first].subTree > mx) {
				mx = g[adj[node][i].first].subTree;
				indx = i;
			}
		}
	}
 
	if(indx == -1)
		return;
 
	hld(adj[node][indx].first, c);
 
	for(int i = 0; i < (int)adj[node].size(); i++) {
		if(adj[node][i].first != g[node].parent && i != indx) {
			chain_head[chains.size()] = adj[node][i].first;
			chains.push_back(vector<int>());
			hld(adj[node][i].first, chains.size() - 1);
		}
	}
}
 
int compine_chain(int a, int b, int c) {
	if(chains[c][a] > chains[c][b])
		return a;
	return b;
}
 
void build_st_chain(int node, int lt, int rt, int c) {
	if(lt == rt) {
		st_chains[c][node] = lt;
	}
	else {
		int mid = (lt + rt) / 2;
		build_st_chain(node * 2, lt, mid, c);
		build_st_chain(node * 2 + 1, mid + 1, rt, c);
		st_chains[c][node] = compine_chain(st_chains[c][node * 2], st_chains[c][node * 2 + 1], c);
	}
}
 
int query_st_chain(int node, int lt, int rt, int lq, int rq, int c) {
	if(lt > rq || rt < lq)
		return -1;
	if(lt >= lq && rt <= rq)
		return st_chains[c][node];
 
	int mid = (lt + rt) / 2;
	int l = query_st_chain(node * 2, lt, mid, lq, rq, c);
	int r = query_st_chain(node * 2 + 1, mid + 1, rt, lq, rq, c);
 
	if(l == -1)return r;
	if(r == -1)return l;
	return compine_chain(l, r, c);
}
 
void build_sts() {
	st_chains.resize(chains.size());
	for(int i = 0; i < (int)chains.size(); i++) {
		st_chains[i].resize(chains[i].size() * 4);
		build_st_chain(1, 0, chains[i].size() - 1, i);
	}
}
 
 
void clear() {
	adj.clear();
	adj.resize(n + 1);
	chains.clear();
	st_chains.clear();
 
}
void setup() {
	eCount = 0;
 
	dfs(1, -1, 0, 0);
 
	build_euler(1, 0, eCount - 1);
 
	chains.clear();
 
	chains.push_back(vector<int> ());
	chain_head[0] = 1;
	hld(1, 0);
	build_sts();
 
}
 
int lca(int a, int b) {
	if(g[a].h > g[b].h) {
		int tmp = a;
		a = b;
		b = tmp;
	}
 
	int l = query_euler(1, 0, eCount - 1, g[a].h , g[b].h);
	return euler[l].first;
}
 
int go_up(int from, int to) {
	int ans = -99999999;
 
	int t, indx;
	while(from != -1) {
 
		if(from == to) {
			ans = max(ans, 0);
			break;
		}
		indx = g[from].chain;
		if(indx == g[to].chain) {
			t = query_st_chain(1, 0, chains[indx].size() -1, g[to].indx + 1, g[from].indx, indx);
			from = to;
		}
		else {
			t = query_st_chain(1, 0, chains[indx].size() -1, 0, g[from].indx, indx);
			from = g[chain_head[indx]].parent;
		}
 
		ans = max(ans, chains[indx][t]);
	}
 
	return ans;
}
int query_max_edge(int a, int b) {
	int l =  lca(a, b);
	return max(go_up(a, l), go_up(b, l));
}
 
void update_chain(int node, int lt, int rt, int indx, int val, int c) {
	if(lt == rt) {
		chains[c][indx] = val;
	}
	else {
		int mid = (lt + rt) / 2;
		if(indx <= mid) {
			update_chain(node * 2, lt, mid, indx, val, c);
		}
		else {
			update_chain(node * 2 + 1, mid + 1, rt, indx, val, c);
		}
		st_chains[c][node] = compine_chain(st_chains[c][node * 2], st_chains[c][node * 2 + 1], c);
	}
}
 
void updater(int a, int b, int val) {
 
	int f = a;
	if(g[b].depth > g[a].depth)
		f = b;
	int indx = g[f].chain;
	update_chain(1, 0, chains[indx].size() -1, g[f].indx, val, indx);
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
	int t, a, b, c;
	scanf("%d", &t);
	char s[100];
 
	while(t--) {
 
		scanf("%d", &n);
		clear();
 
 
		vector<pair<int, int> > edj;
		for(int i = 1; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
			edj.push_back(make_pair(a, b));
		}
 
		setup();
 
		while(true) {
			scanf("%s", s);
			if(s[0] == 'D')
				break;
 
			scanf("%d %d", &a, &b);
			if(s[0] == 'Q') {
				printf("%d\n",query_max_edge(a, b));
				lca(a, b);
			}
			else {
				a--;
				updater(edj[a].first, edj[a].second, b);
			}
		}
 
	}// end
 
 
	return 0;
}
 
 
 
 
 
 
 
 

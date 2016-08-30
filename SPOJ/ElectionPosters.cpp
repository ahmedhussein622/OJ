#include <bits/stdc++.h>
 
using namespace std;
int st[400000];
 
int n, cnt;
vector<pair<int, int> > query;
map<int, int> compress;
 
 
int update(int node, int lt, int rt, int lq, int rq) {
	if(lt > rq || rt < lq)
		return 0;
 
	int len = rt - lt + 1;
	if(st[node] == len)
		return 0;
 
	if(lt >= lq && rt <= rq) {
		int a = st[node];
		st[node] = len;
		return len - a;
	}
 
	int left = update(node * 2, lt, (lt + rt) / 2, lq, rq);
	int right = update(node * 2 + 1, (lt + rt) / 2 + 1, rt, lq, rq);
	st[node] += left + right;
	return left + right;
}
 
 
 
int processor() {
 
	compress.clear();
 
 
	set<int> ss;
 
	for(int i = 0; i < n; i++) {
		ss.insert(query[i].first);
		ss.insert(query[i].second);
	}
 
	cnt = 1;
	for(set<int>::iterator it = ss.begin(); it != ss.end(); it++) {
		if(compress[*it] == 0)
				compress[*it] = cnt++;
	}
 
	cnt--;
 
	memset(st, 0 , sizeof st);
 
 
	int ans = 0;
 
	int pre = 0;
	for(int i = n - 1; i >= 0; i--) {
		update(1, 1, cnt, compress[query[i].first], compress[query[i].second] - 1);
		if(pre != st[1]) {
			ans ++;
		}
		pre = st[1];
	}
 
 
	query.clear();
	return ans;
}
 
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt","r", stdin);
	int t, a, b;
	scanf("%d", &t);
 
	while(t--) {
 
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			query.push_back(make_pair(a, b + 1));
		}
 
		printf("%d\n",processor());
 
	}
 
 
 
    return 0;
}
 
 
 
 
 
 
 
 

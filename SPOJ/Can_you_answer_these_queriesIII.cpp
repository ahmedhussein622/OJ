#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
class Node {
public:
	int sum, pref, suf, ans;
	Node() {
		sum = pref = suf = ans = 0;
	}
};
 
Node st[50000 * 4];
int a[50000];
int n;
 
void build(int node, int l, int r) {
	if(l == r) {
		st[node].sum = st[node].pref = st[node].suf = st[node].ans = a[l];
	}
	else {
		int left = node * 2;
		int right = left + 1;
		build(left, l, (l + r) / 2);
		build(right,(l + r) / 2 + 1, r);
		st[node].sum = st[left].sum +  st[right].sum;
		st[node].pref = max(st[left].pref, st[left].sum + st[right].pref);
		st[node].suf = 	max(st[right].suf, st[right].sum + st[left].suf);
		st[node].ans = max(max(st[left].ans, st[right].ans),st[left].suf + st[right].pref);
	}
}
 
void update(int node, int lt, int rt, int indx, int val) {
	if(lt == rt) {
		st[node].sum = st[node].pref = st[node].suf = st[node].ans = val;
	}
	else {
		int mid = (lt + rt) / 2;
		if(indx <= mid) {
			update(node * 2, lt, mid, indx, val);
		}
		else {
			update(node * 2 + 1, mid + 1, rt, indx, val);
		}
 
		int left = node * 2;
		int right = left + 1;
 
		st[node].sum = st[left].sum +  st[right].sum;
		st[node].pref = max(st[left].pref, st[left].sum + st[right].pref);
		st[node].suf = 	max(st[right].suf, st[right].sum + st[left].suf);
		st[node].ans = max(max(st[left].ans, st[right].ans),st[left].suf + st[right].pref);
	}
}
 
Node * query(int node, int lt, int rt, int lq, int rq) {
	if(lt >= lq && rt <= rq) {
		return &st[node];
	}
	if(lt > rq || rt < lq)
		return NULL;
 
	Node * left = query(node * 2, lt, (lt + rt)/ 2, lq, rq);
	Node * right = query(node * 2 + 1, (lt + rt)/ 2 + 1, rt, lq, rq);
 
	if(left == NULL)
		return right;
	if(right == NULL)
		return left;
 
	Node * ans = new Node();
 
	ans->sum = 	left->sum +  right->sum;
	ans->pref = max(left->pref, left->sum + right->pref);
	ans->suf = 	max(right->suf, right->sum + left->suf);
	ans->ans = max(max(left->ans, right->ans),left->suf + right->pref);
 
	return ans;
}
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a+i);
 
	build(1, 0, n - 1);
	int m;
	scanf("%d", &m);
 
	int a, b, c;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0) {
			update(1,0, n-1,b - 1,c);
		}
		else {
			Node * ans = query(1, 0, n - 1, b - 1, c - 1);
			cout<<ans->ans<<endl;
		}
	}
 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

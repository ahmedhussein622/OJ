#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
class Node {
public :
	int pref,suf,sum,ans;
	Node * left,*right;
	Node() {
		pref = suf = sum = ans = 0;
		left = right = NULL;
	}
	Node(int pref_,int suf_,int sum_, int ans_) {
		pref = pref_;
		suf = suf_;
		sum = sum_;
		ans = ans_;
		left = right = NULL;
	}
};
 
 
class Tree {
public:
	Node * root;
	int n;
	int a[50010];
	Tree() {
		n = 0;
		root = NULL;
	}
 
 
	Node * build(int lt, int rt) {
		if(lt == rt) {
			Node * r = new Node(a[lt], a[lt], a[lt], a[lt]);
			return r;
		}
		Node * left = build(lt, (lt + rt) / 2);
		Node * right = build((lt + rt) / 2 + 1, rt);
		Node * r = new Node();
 
		r->sum = left->sum + right->sum;
		r->pref = max(left->pref, left->sum + right->pref);
		r->suf = max(right->suf, right->sum + left->suf);
		r->ans = max(max(left->ans, right->ans),left->suf + right->pref);
		r->left = left;
		r->right = right;
		return r;
	}
 
	void build() {
		root = build(0, n - 1);
	}
 
	Node * query(Node * node, int lt, int rt, int lq, int rq) {
//		cout<<"query : "<<lt<<", "<<rt<<" ...  "<<lq<<" "<<rq<<endl;
 
		if(lt > rq || rt < lq)
			return NULL;
 
 
		if(lt >= lq && rt <= rq) {
			return node;
		}
 
		int mid = (lt + rt) / 2;
 
		Node * left = query(node->left, lt, mid, lq, rq);
		Node * right = query(node->right, mid + 1, rt, lq, rq);
		if(left == NULL)
			return right;
		if(right == NULL)
			return left;
 
		Node * r = new Node();
		r->sum = left->sum + right->sum;
		r->pref = max(left->pref, left->sum + right->pref);
		r->suf = max(right->suf, right->sum + left->suf);
		r->ans = max(max(left->ans, right->ans),left->suf + right->pref);
 
		return r;
	}
 
 
	int query(int l, int r) {
 
		Node * ans = query(root, 0, n - 1, l, r);
		return ans->ans;
	}
};
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	Tree t;
	scanf("%d", &t.n);
	for(int i = 0; i < t.n; i++) {
		scanf("%d",&t.a[i]);
	}
 
 
	t.build();
 
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int l,r;
		scanf("%d %d", &l, &r);
 
		printf("%d\n",t.query(--l, --r));
	}
}
 
 
 
 
 
 
 

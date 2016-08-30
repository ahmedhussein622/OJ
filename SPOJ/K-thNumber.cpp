#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
	Node * left, *right;
	int sum;
	Node() {
		left  = right = NULL;
		sum = 0;
	}
};
 
Node * build(int lt, int rt) {
	if(lt == rt) {
		return new Node();
	}
	Node * ans = new Node();
	ans->left = build(lt, (lt + rt) / 2);
	ans->right = build((lt + rt) / 2 + 1, rt);
	return ans;
}
 
Node * update(Node * oldNode, int lt, int rt, int indx) {
	Node * ans = new Node();
	if(lt == rt) {
		ans->sum = 1;
	}
	else {
		int mid = (lt + rt) / 2;
		ans->left = oldNode->left;
		ans->right = oldNode->right;
		if(indx <= mid)
			ans->left = update(oldNode->left, lt, mid, indx);
		else
			ans->right = update(oldNode->right, mid + 1, rt, indx);
 
		ans->sum = ans->left->sum + ans->right->sum;
	}
 
	return ans;
}
 
int query(Node * node, int lt, int rt, int lq, int rq) {
 
	if(lt > rq || rt < lq)
		return 0;
 
	if(lt == rt || (lt >= lq && rt <= rq))
		return node->sum;
 
	return query(node->left, lt, (lt + rt) / 2, lq, rq) + query(node->right, (lt + rt) / 2 + 1, rt, lq, rq);
}
 
 
vector<pair<int, int > > input;
int n, m;
vector<Node*>roots;
 
void preProcessor() {
	Node * pre = build(0, n - 1);
	for(int i = 0; i < n; i++) {
		pre = update(pre, 0, n - 1, input[i].second);
		roots.push_back(pre);
	}
}
 
 
 
int solve(int lq, int rq, int k) {
 
	int left = 0;
	int right = n;
 
	while(left < right) {
		int mid = (left + right) / 2;
		int c = query(roots[mid], 0, n - 1, lq, rq);
		if(c >= k) {
			right = mid;
		}
		else {
			left =  mid + 1;
		}
	}
 
	return input[left].first;
}
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt","r", stdin);
	scanf("%d %d", &n, &m);
 
	int a, b, c;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		input.push_back(make_pair(a, i));
	}
 
	sort(input.begin(), input.end());
 
	preProcessor();
 
//	for(int i = 0; i < n; i++) {
//		printf("ll %d %d\n",input[i].first, query(roots[i], 0, n - 1, 1, 8));
//	}
 
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n",solve(a - 1, b - 1, c));
	}
 
 
 
    return 0;
}
 
 
 
 
 
 
 
 
 

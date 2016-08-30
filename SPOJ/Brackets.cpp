#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[30100];
 
class Node {
public:
	int sum,minimum;
	Node() {
		sum = minimum = 0;
	}
};
 
 
Node st[30010 * 4];
 
void compine(Node * a, Node * left, Node * right) {
	if(left == NULL) {
		a->sum = right->sum;
		a->minimum = right->minimum;
	}
	else if(right == NULL) {
		a->sum = left->sum;
		a->minimum = left->minimum;
	}
	else {
		a->sum = left->sum + right->sum;
		a->minimum = min(left->minimum, left->sum + right->minimum);
	}
}
 
void build(int node, int lt, int rt) {
	if(lt == rt) {
		st[node].sum = a[lt];
		st[node].minimum = a[lt];
	}
	else {
		int mid = (lt + rt) / 2;
		build(node * 2, lt, mid);
		build(node * 2 + 1, mid + 1, rt);
		compine(&st[node],&st[node * 2], &st[node * 2 + 1]);
	}
}
 
void update(int node, int lt, int rt, int indx) {
	if(lt == rt) {
		a[indx] = a[indx] == 1 ? -1 : 1;
		st[node].sum = a[lt];
		st[node].minimum = a[lt];
	}
	else {
		int mid  = (lt + rt) / 2;
		if(indx <= mid) {
			update(node * 2, lt, mid, indx);
		}
		else {
			update(node * 2 + 1, mid + 1, rt, indx);
		}
		compine(&st[node],&st[node * 2], &st[node * 2 + 1]);
	}
}
 
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	int  t = 10;
	int m, q;
	char c;
	for(int ii = 1; ii <= t; ii++) {
		printf("Test %d:\n", ii);
		scanf("%d\n", &n);
		for(int i = 0; i < n;i++) {
			scanf("%c", &c);
			a[i] = c =='(' ? 1 : -1;
		}
		build(1, 0, n - 1);
		scanf("%d\n", &m);
		for(int i  = 0; i < m;i++) {
			scanf("%d", &q);
			if(q == 0){
				if(st[1].sum == 0 && st[1].minimum >= 0) {
					printf("YES\n");
				}
				else {
					printf("NO\n");
				}
			}
			else {
				update(1,0, n-1, q - 1);
			}
		}
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

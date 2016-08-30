#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
long long a[500000], lazyA[500000];
 
 
 
void build() {
	memset(a, 0, sizeof a);
	memset(lazyA, 0, sizeof lazyA);
}
 
void lazyUpdate(long long node, long long lt, long long rt) {
	a[node] += lazyA[node] * (rt - lt + 1);
 
	if(lt != rt) {
		lazyA[node * 2] += lazyA[node];
		lazyA[node * 2 + 1] += lazyA[node];
	}
 
	lazyA[node] = 0;
}
 
void update(long long node, long long lt, long long rt, long long lq, long long rq, long long val) {
 
	lazyUpdate(node, lt, rt);
 
	if(rt < lq || lt > rq)
		return;
 
	if(lt == rt) {
		a[node] += val;
		return;
	}
 
 
 
	if(lt >= lq && rt <= rq) {
		a[node] += val * (rt - lt + 1);
		lazyA[node * 2] += val;
		lazyA[node * 2 + 1] += val;
	}
	else {
		update(node * 2, lt, (lt + rt) / 2, lq, rq, val);
		update(node * 2 + 1,(lt + rt) / 2 + 1, rt, lq, rq, val);
		a[node] = a[node * 2] + a[node * 2 + 1];
	}
 
}
 
long long query(long long node, long long lt, long long rt, long long lq, long long rq) {
 
	lazyUpdate(node, lt, rt);
 
	if(lt > rq || rt < lq)
		return 0;
 
	if(lt >= lq && rt <= rq)
		return a[node];
 
 
	long long ans = query(node * 2, lt, (lt + rt) / 2, lq, rq);
	ans += query(node * 2 + 1,(lt + rt) / 2 + 1, rt, lq, rq);
 
	return ans;
}
 
//void prlong longer(long long node, long long lt, long long rt) {
//	prlong longf("start : %d, %d, %d, %d, %d\n", node, lt, rt, a[node], lazyA[node]);
//	if(lt == rt)
//		return;
//	prlong longer(node * 2, lt, (lt + rt) / 2);
//	prlong longer(node * 2 + 1, (lt + rt) / 2 + 1, rt);
//	prlong longf("   done : %d, %d, %d, %d, %d\n", node, lt, rt, a[node], lazyA[node]);
//}
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt", "r", stdin);
	long long t;
	scanf("%lld", &t);
	long long n,m, c,p,q,v;
	while(t--) {
 
		scanf("%lld %lld", &n, &m);
		build();
		for(long long i = 0; i < m; i++) {
 
			scanf("%lld %lld %lld", &c, &p, &q);
			p--;
			q--;
			if(c) {
				printf("%lld\n", query(1, 0, n-1, p, q));
			}
			else {
				scanf("%lld", &v);
				update(1, 0, n-1, p, q, v);
			}
//			prlong longf("%d %d %d\n",c, p, q);
//			prlong longer(1, 0, n - 1);
//			prlong longf("--------------------------------------------\n");
		}
	}
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#include<bits/stdc++.h>
using namespace std;
 
 
long long merger(int a[], int b[], int l, int mid, int r) {
 
	long long ans = 0;
 
	int g = l;
	int h = mid + 1;
	int k = l;
 
	while(g <= mid && h <= r) {
		if(a[g] <= a[h]) {
			b[k] = a[g++];
			ans += (h - mid - 1);
		}
		else {
			b[k] = a[h++];
		}
		k++;
	}
 
	while(g <= mid) {
		b[k++] = a[g++];
		ans += (h - mid - 1);
	}
 
	while(h <= r) {
		b[k++] = a[h++];
	}
 
	for(int i = l; i <= r; i++)
		a[i] = b[i];
 
 
	return ans;
 
}
 
 
long long solve(int a[], int b[], int l, int r) {
	if(l == r)
		return 0;
	long long ans = 0;
 
	int mid = (l + r) / 2;
	ans += solve(a, b, l, mid);
	ans += solve(a, b, mid + 1, r);
	ans += merger(a, b, l, mid, r);
 
	return ans;
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	int t, n;
	scanf("%d", &t);
	int a[200100], b[200100];
 
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		long long ans = solve(a, b, 0, n - 1);
		printf("%lld\n", ans);
	}
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

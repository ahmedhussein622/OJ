#include<bits/stdc++.h>
using namespace std;
 
int k;
pair<long long, long long> dp1[30010], dp2[30010];
 
class RK {
public:
	long long hash, bk;
	long long base, mod;
 
	RK(long long b, long long m) {
		base = b;
		mod = m;
 
		hash = 0;
		bk = 1;
	}
 
	void add(int d) {
		hash = (hash * base) % mod;
		hash = (hash + d) % mod;
	}
 
	void remove(long long d) {
 
		d = (d * bk) % mod;
		hash = (hash - d + mod) % mod;
	}
 
	void mult_b() {
		bk = (bk * base) % mod;
	}
 
 
};
 
char s[30010];
int n;
 
 
void worker(pair<long long, long long> dp[]) {
 
	RK a(47, 1e11 + 3);
	RK b(79, ((long long)1 << 31) - 1);
 
	a.add(s[0] - 'a');
	b.add(s[0] - 'a');
 
	for(int i = 1; i < k && i < n; i++) {
 
		a.mult_b();
		a.add(s[i] -'a');
 
		b.mult_b();
		b.add(s[i] -'a');
 
	}
 
	dp[k - 1] = make_pair(a.hash, b.hash);
 
	for(int i = k; i < n; i++) {
		a.remove(s[i - k] - 'a');
		a.add(s[i] -'a');
 
		b.remove(s[i - k] - 'a');
		b.add(s[i] -'a');
 
		dp[i] = make_pair(a.hash, b.hash);
	}
 
}
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
	scanf("%d", &k);
	scanf("%s", s);
	n = strlen(s);
 
	worker(dp1);
	reverse(s, s + n);
	worker(dp2);
 
	int ans = 0;
 
 
	for(int i = k - 1, j = n - 1; i < n; i++, j--) {
		auto a = dp1[i];
		auto b = dp2[j];
 
		if(a.first == b.first && a.second == b.second)
			ans++;
	}
 
 
	printf("%d\n", ans);
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

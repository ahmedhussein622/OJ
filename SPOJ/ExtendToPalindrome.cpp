#include<bits/stdc++.h>
using namespace std;
 
 
char s[100100];
int n;
 
class RK {
 
public :
 
	long long mod, base;
	long long hash, b;
 
 
	RK(long long m, long long bs) {
		mod = m;
		base = bs;
		hash = 0;
		b = 1;
	}
 
	void add_right(int d) {
		hash = (hash * base) % mod;
		hash = (hash + d) % mod;
	}
 
	void add_left(int d) {
		hash = (hash + b * d) % mod;
		b = (b * base) % mod;
	}
};
 
 
int main() {
 
//	freopen("input.txt", "r", stdin);
 
 
	while(scanf("%s", s) != EOF) {
		n = strlen(s);
 
		int indx = n;
		RK l1(1e9 + 7, 57);
		RK r1(1e9 + 7, 57);
 
		RK l2(2147483647, 79);
		RK r2(2147483647, 79);
 
		for(int i = n - 1; i >= 0; i--) {
			int d;
			if(s[i] >= 'a' && s[i] <= 'z')
				d = s[i] - 'a';
			else
				d = s[i] - 'A' + 26;
 
			l1.add_left(d);
			r1.add_right(d);
 
			l2.add_left(d);
			r2.add_right(d);
 
			if(l1.hash == r1.hash && l2.hash == r2.hash)
				indx = i;
		}
 
		printf("%s", s);
		for(int i = indx - 1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
 
 
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

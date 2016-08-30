#include <bits/stdc++.h>
 
using namespace std;
int n, q, block;
int a[40000];
vector<pair<pair<int, int>, int > >query;
 
bool compare(pair<pair<int, int>, int > a, pair<pair<int, int>, int > b) {
	int la = a.first.first / block;
	int lb = b.first.first / block;
	if(la != lb)
		return la < lb;
	return a.first.second < b.first.second;
}
 
int ans = 0;
int freq[1001000];
void add(int x) {
	if(freq[x] == 0)
		ans++;
	freq[x]++;
}
void remover(int x) {
	if(freq[x] == 1)
		ans--;
	freq[x]--;
}
 
 
 
int main(int argc, char **argv) {
 
//	freopen("input.txt","r", stdin);
	scanf("%d", &n);
	for(int i = 0;i < n; i++) {
		scanf("%d", a + i);
	}
 
	scanf("%d", &q);
	int l,r;
	for(int i = 0; i < q; i++) {
		scanf("%d %d", &l, &r);
		query.push_back(make_pair(make_pair(l - 1, r - 1), i));
	}
 
	block = (int) sqrt(n);
//	block = 555;
 
 
	sort(query.begin(), query.end(), compare);
	int result[q];
 
	memset(freq, 0, sizeof freq);
 
	int left = 0;
	int right = -1;
 
 
	for(int i = 0; i < q; i++) {
		l = query[i].first.first;
		r = query[i].first.second;
		while(right < r)
			add(a[++right]);
		while(right > r)
			remover(a[right--]);
		while(left < l)
			remover(a[left++]);
		while(left > l)
			add(a[--left]);
 
		result[query[i].second] = ans;
	}
 
 
	for(int i = 0; i < q; i++) {
		printf("%d\n", result[i]);
	}
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

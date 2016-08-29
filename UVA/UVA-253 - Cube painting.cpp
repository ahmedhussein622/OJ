#include<stack>
#include <bits/stdc++.h>
using namespace std;


void rotate_x(char a[]) {
	char tmp = a[0];
	a[0] = a[1];
	a[1] = a[5];
	a[5] = a[4];
	a[4] = tmp;
}

void rotate_y(char a[]) {
	char tmp = a[0];
	a[0] = a[3];
	a[3] = a[5];
	a[5] = a[2];
	a[2] = tmp;
}

void rotate_z(char a[]) {
	char tmp = a[1];
	a[1] = a[2];
	a[2] = a[4];
	a[4] = a[3];
	a[3] = tmp;
}



int main() {

//	freopen("input.txt", "r", stdin);

	char a[13];
	char b[6], c[6];

	while(scanf("%s", a) != EOF) {

		memcpy(b, a, 6);
		memcpy(c, a + 6, 6);

		bool ans = false;


		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				ans |= (memcmp(b, c, sizeof(c)) == 0);
				rotate_z(c);
			}
			rotate_y(c);
		}

		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				ans |= (memcmp(b, c, sizeof(c)) == 0);
				rotate_z(c);
			}
			rotate_x(c);
		}

		if(ans)
			printf("TRUE\n");
		else
			printf("FALSE\n");

	}

	return 0;
}














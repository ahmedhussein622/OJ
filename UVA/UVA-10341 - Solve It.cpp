#include <bits/stdc++.h>


using namespace std;

int p, q, r, s, t, u;


double fun(double x) {

//	p ∗ e−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x2 + u = 0
	double ans = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
	return ans;
}


int main() {


//	freopen("input.txt", "r", stdin);

	double eps = 10e-10;

	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if(fun(0) * fun(1) > 0)
			printf("No solution\n");
		else {
//			printf("%lf %lf\n", fun(0), fun(1.0));
			double l = 0;
			double r = 1.0;
			double d;

			if(abs(fun(0)) < eps)
				d = 0;
			else if(abs(fun(1)) < eps)
				d = 1.0;
			else {
				while(1) {
					d = (l + r) / 2;
					double f = fun(d);

					if(abs(f) < eps)
						break;
					if(f * fun(r) >= 0)
						r = d;
					else
						l = d;

				}
			}

			d = round(d * 10000) / 10000.0;
			printf("%.4lf\n", d);

		}

	}


	return 0;
}

































#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, T;
	pair<int, int> p[1005];
	double PI = acos(-1);

	double v[1005];

	while(scanf("%d %d", &n, &T) == 2){
		for(int i = 0; i < n; i++)
			scanf("%d %d", &p[i].ff, &p[i].ss);

		double x = 0, y = 0, a, b;

		// cos -sen
		// sen cos

		for(int i = 0; i < n; i++){
			double ang = 1.0*(T % p[i].ss)/p[i].ss * 2*PI;
			a = p[i].ff*cos(ang);
			b = p[i].ff*sin(ang);
			x += a;
			y += b;
			v[i] = sqrt(x*x + y*y);
		}
		printf("%.4lf", v[0]);
		for(int i = 1; i < n; i++)
			printf(" %.4lf", v[i]);
		printf("\n");
	}

	return 0;
}
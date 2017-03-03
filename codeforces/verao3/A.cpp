#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

double pi = acos(-1);

int main(){
	int n, r, v[2000];

	scanf("%d %d", &n, &r);

	double ans = pi*r*r*n;

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);
	sort(v, v+n);

	for(int i = 0; i < n-1; i++){

		int delta = v[i+1] - v[i];
		if(delta >= 2*r) continue;
		double d = delta/2.0;

		double theta = acos(d/r);

		double at = d*r*sin(theta);

		ans -= 2*(r*r*theta - at);
	}

	printf("%.10lf\n", ans);

	return 0;
}
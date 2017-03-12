#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
int x[60004];
int v[60004];

double f(double mid){
	double mx, mn;

	// mx = mn = x[0] + v[0]*mid;
	mx = mn = fabs(x[0] - mid)/v[0];
	for(int i = 0; i < n; i++){
		// double tmp = x[i] + v[i]*mid;
		double tmp = fabs(x[i] - mid)/v[i];
		mx = max(mx, tmp);
		mn = min(mn, tmp);
	}
	return mx;
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", x+i);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	double hi = 1e20, lo = 0;

	for(int q = 0; q < 200; q++){
		double tmp = (hi - lo) / 3;
		double mid1 = lo + tmp;
		double mid2 = hi - tmp;

		if(f(mid1) <= f(mid2)) hi = mid2;
		else lo = mid1;
	}

	printf("%lf\n", f(lo));




	return 0;
}
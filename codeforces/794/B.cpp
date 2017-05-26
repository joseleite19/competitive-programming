#include <bits/stdc++.h>

using namespace std;

long long n;
double h;

double f2(double mid){
	double b = mid/h;
	return b*mid/2;
}

double f(double area){
	double lo = 0, hi = h;

	for(int i = 0; i < 100; i++){
		double mid = (lo + hi) / 2;
		if(f2(mid) < area) lo = mid;
		else hi = mid;
	}
	return hi;
}

int main(){

	scanf("%lld %lf", &n, &h);

	double a = h/2.0/n;
	double tot = 0;

	for(int i = 1; i < n; i++){
		tot += a;

		printf("%lf ", f(tot));
	}
	printf("\n");

	return 0;
}
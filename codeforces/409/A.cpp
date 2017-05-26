#include <bits/stdc++.h>

using namespace std;

int n, p;
int a[100005], b[100005];


bool f(double mid){

	double sum = 0;
	for(int i = 0; i < n; i++)
		if(mid*a[i] > b[i] + 1e-6)
			sum += mid*a[i] - b[i];

	return mid*p >= sum;
}

int main(){

	scanf("%d %d", &n, &p);

	for(int i = 0; i < n; i++)
		scanf("%d %d", a+i, b+i);

	long double lo = 0, hi = 1e50;

	for(int i = 0; i < 500; i++){
		long double mid = (lo + hi) / 2;
		if(f(mid)) lo = mid;
		else hi = mid;
	}

	if(hi > 1e49) hi = -1;

	printf("%lf\n", (double)hi);


	return 0;
}
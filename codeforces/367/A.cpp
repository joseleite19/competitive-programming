#include <bits/stdc++.h>

#define ff first
#define ss second

#define oo 1000000000

using namespace std;

int main(){
	int a, b;
	int x, y, v, n;
	double ans = 1e50;

	scanf("%d %d", &a, &b);

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &x, &y, &v);
		double d = sqrt((x-a)*(x-a) + (y-b)*(y-b));
		ans = min(ans, d / v);
	}

	printf("%.20lf\n", ans);

	return 0;
}
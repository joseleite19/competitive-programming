#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int s, m, p;
long double eps = 0;
int f(long double x){

	long double left = s;
	// printf("%Lf %Lf\n", x, left);

	for(int i = 0; i < m; i++){
		long double a, b;
		a = left * p / 100;
		b = x - a;
		// if(b + eps < 0) return 0;
		// if(b + eps < 0) break;

		left -= b;
		// if(left + eps < 0) return 0;
	}
	// printf("%Lf %Lf\n", x, left);
	
	if(left + eps < 0) return 0;
	return 1;
}

int main(){

	scanf("%d %d %d", &s, &m, &p);

	long double ans = 0;

	long double hi = 1e30, lo = 0;

	for(int k = 0; k < 10000; k++){
		long double mid = (lo + hi) / 2;
		int ret = f(mid);
		if(ret == 0){
			hi = mid;
		}
		else lo = mid;
	}
	// printf("%lf %lf\n", (double)lo, (double)hi);

	printf("%.20Lf\n", lo);





	return 0;
}
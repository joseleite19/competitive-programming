#include <bits/stdc++.h>

using namespace std;

long long v[200005];

int main(){
	int n;

	double PI = acos(-1);
	int v = 2;

	printf("%.20lf %lf\n", PI + (PI - (10 - (3 + 2*PI)))/2, 10 - 3 - 2*PI);// acos(10 - (3 + 2*PI))/PI, 3 + 2*PI);

	int r = 1;
	int ini = 1;
	int fim = 10;
	int k = 1;
	ini = ini + 2*r;

	double theta = (fim - ini - 2*PI*k)/r;
	double alfa = PI - theta;

	printf("%.15lf %lf\n", (fim - ini + (r*(alfa)))/v, (alfa) );

	printf("3.849644710502\n");
	return 0;
}
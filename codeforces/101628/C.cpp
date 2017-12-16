#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

double ax, ay, bx, by, d;

double getd(double x){
	double c = by*by + (x - bx) * (x - bx) - d;
	double b = -2;
	double a = 1;
	double delta = b * b - 4 * a * c;
	double y = (-b + sqrt(delta)) / (2 * a);
	return sqrt((y - by) * (y - by) + (x - (bx-d)) * (x - (bx-d)));
}

double rx(double x, double y){
	
}

int main(){

	scanf("%lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &d);

	double lo = bx - d, hi = bx + d;

	forn(i, 100){
		double mid = (lo + hi) * 0.5;
		if(getd(mid) < d) lo = mid;
		else hi = mid;
	}
	
	double c = by*by + (x - bx) * (x - bx) - d;
	double b = -2;
	double a = 1;
	double delta = b * b - 4 * a * c;
	double y1 = (-b +sqrt(delta)) / (2 * a);
	double y2 = (-b -sqrt(delta)) / (2 * a);
	double x1, x2;
	x1 = x2 = lo;

	double xx1, yy1, xx2, yy2;

	xx1 = rx(x1, y1);
	yy1 = ry(x1, y1);
	xx2 = rx(x2, y2);
	yy2 = ry(x2, y2);

	if(fabs(yy1 - yy2) < 1e9 && fabs(xx1 - xx2) < 1e9) printf("NO\n");
	else{
		printf("YES\n");
		printf("%.10lf %.10lf %.10lf %.10lf\n",);
	}
	



    return 0;
}

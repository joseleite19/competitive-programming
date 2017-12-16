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

int a, v, l, d, w;

double gett(double e, double r){
	return abs(r - e) / a;
}

double gets(double e, double r){
	double t = gett(e, r);
	double aa = r > e ? a : -a;
	return e * t + aa * t * t / 2;
}


int main(){

	scanf("%d %d %d %d %d", &a, &v, &l, &d, &w);

	if(v < w){
		double L = 0, R = v;

		forn(i, 100){
			double mid = (L+R)*0.5;
			if(gets(0, mid) > l) R = mid;
			else L = mid;
		}

		double ans = gett(0, L);
		ans += (l - gets(0, L)) / v;

		printf("%.20lf\n", ans);
		return 0;
	}

	double L = 0, R = v; // peak

	double lim = min<double>(w, sqrt(a * d * 2));

	forn(i, 100){
		double mid = (L+R)*0.5;
		if(gets(0, mid) + gets(mid, lim) > d) R = mid;
		else L = mid;
	}

	double ans = 0;

	ans += gett(0, L) + gett(L, lim);
	ans += (d - (gets(0, L) + gets(L, lim))) / v;

	L = lim, R = v;
	
	forn(i, 100){
		double mid = (L+R)*0.5;
		if(gets(lim, mid) > l-d) R = mid;
		else L = mid;
	}

	ans += gett(lim, L);
	ans += (l - d - gets(lim, L)) / v;

	printf("%.20lf\n", ans);


    return 0;
}

#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
int n;

pair<long long, long long> v[1003];

double dist(int i, int j){
	return sqrt((v[i].ff - v[j].ff)*(v[i].ff - v[j].ff)+
				(v[i].ss - v[j].ss)*(v[i].ss - v[j].ss));
}

double check(int i){
	int j = (i - 1 + n) % n;
	int k = (i + 1) % n;

	double a = v[j].ss - v[k].ss;
	double b = v[k].ff - v[j].ff;
	double c = v[j].ff * v[k].ss - v[j].ss * v[k].ff;

	double x = (b*(b*v[i].ff - a*v[i].ss) - a*c)/(a*a + b*b);
	double y = (a*(-b*v[i].ff + a*v[i].ss) - b*c)/(a*a + b*b);

	return fabs(a*v[i].ff + b*v[i].ss + c) / sqrt(a*a + b*b);
}

int main(){
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &v[i].ff, &v[i].ss);

	double lo = 0, hi = 1e50;

	for(int i = 0; i < n; i++)
		hi = min(hi, check(i));
	hi /= 2;

	printf("%.20lf\n", hi);

	return 0;
}
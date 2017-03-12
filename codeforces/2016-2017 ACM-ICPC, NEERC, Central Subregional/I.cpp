#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

double dis(pair<double, double> p, pair<double, double> q){
	return sqrt((p.ff - q.ff) * (p.ff - q.ff) + (p.ss - q.ss) * (p.ss - q.ss));
}

struct line{
	double a, b, c;

	pair<double, double> w, e;

	line(pair<double, double> p, pair<double, double> q){
		a = -(p.ss - q.ss);
		b = p.ff - q.ff;
		e = p;
		w = q;

		c = -(a*p.ff + b*p.ss);
	}
	double dist(pair<double, double> p){
		double ans = fabs(a*p.ff + b*p.ss + c)/ sqrt(a*a + b*b);

		double x = (b*( b*p.ff - a*p.ss) - a*c)/(a*a + b*b);
		double y = (a*(-b*p.ff + a*p.ss) - b*c)/(a*a + b*b);
		if(fabs(w.ff - e.ff) < 1e-9){
			if(min(w.ss, e.ss) <= y && y <= max(w.ss, e.ss)) return ans;
		}
		else if(min(w.ff, e.ff) <= x && x <= max(w.ff, e.ff)) return ans;
		return min(dis(w, p), dis(e, p));
	}
};

int n, m, k;
pair<double, double> v[102];

int main(){
	// file();

	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < n; i++)
		scanf("%lf %lf", &v[i].ff, &v[i].ss);

	if(m+k != n+2 && m+k != n+3 && m+k != n+4){
		printf("-1\n");
		return 0;
	}

	double ans = 1e50;

	if(m+k == n+2){ // n+2  vx - vx
		for(int i = 0; i < n; i++){
			ans = min(ans, dis(v[i], v[(i+k-1+n)%n]));
		}
	}
	else if(m+k == n+3){ // n+3  vx - ln
		// k = min(m, k);
		for(int i = 0; i < n; i++){
			// printf("%d -> (%d, %d)\n", i, (i+k-1+n)%n, (i+k-2+n)%n);
			ans = min(ans, line(v[(i+k-1+n)%n], v[(i+k-2+n)%n]).dist(v[i]));
			ans = min(ans, line(v[(i+m-1+n)%n], v[(i+m-2+n)%n]).dist(v[i]));
			ans = min(ans, line(v[(i+k-2+n)%n], v[(i+k-1+n)%n]).dist(v[i]));
			ans = min(ans, line(v[(i+m-2+n)%n], v[(i+m-1+n)%n]).dist(v[i]));
		}
	}
	else if(m+k == n+4){ // n+4  ln - ln
		k = max(m, k);
		for(int i = 0; i < n; i++){
			// printf("%d -> (%d, %d)\n", i, (i+k-1+n)%n, (i+k-2+n)%n);
			ans = min(ans, line(v[(i+k-1+n)%n], v[(i+k-2+n)%n]).dist(v[i]));
			ans = min(ans, line(v[(i+k-2+n)%n], v[(i+k-1+n)%n]).dist(v[i]));
			ans = min(ans, line(v[(i+k-1+n)%n], v[(i+k-2+n)%n]).dist(v[(i+1)%n]));
			ans = min(ans, line(v[(i+k-2+n)%n], v[(i+k-1+n)%n]).dist(v[(i+1)%n]));
		}
	}

	printf("%lf\n", ans);

	return 0;
}
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;

long long vx[100005], vy[100005];
long long rx[100005], ry[100005];
long long x1, yy1, x2, y2;

bool equals(double a, double b){
	return fabs(a - b) < 1e-10;
}

class Point{
public:
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y){}
};

class Line {
public:
    double a;
    double b;
    double c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    Line(const Point& p, const Point& q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;

        double k = a ? a : b;

        a /= k;
        b /= k;
        c /= k;
    }
     bool operator==(const Line& r) const
    {
        return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
    }
};

pair<int, Point> intersections(const Line& r, const Line& s)
{
    auto det = r.a * s.b - r.b * s.a;

    if (equals(det, 0)){
        // Coincidentes ou paralelas
        int qtd = (r == s) ? -1 : 0;

        return pair<int, Point>(qtd, Point());
    } else
    {
        // Concorrentes
        double x = (-r.c * s.b + s.c * r.b) / det;
        double y = (-s.c * r.a + r.c * s.a) / det;

        return pair<int, Point>(1, Point(x, y));
    }
}

double d(double x1, double y1, double x2, double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

bool contains(const Point& A, const Point& B, const Point& P){
    if (equals(A.x, B.x))
        return min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y);
    else
        return min(A.x, B.x) <= P.x and P.x <= max(A.x, B.x);
}

double getmin(int i, long long a, long long b, long long c, long long dd){
	pair<int, Point> p;

	p = intersections(Line(Point(rx[i], ry[i]), Point(rx[i]+vx[i], ry[i] + vy[i])),
				      Line(Point(a, b), Point(c, dd)));

	if(p.ff == 1 && contains(Point(a, b), Point(c, dd), p.ss)){
		if(((!equals(x1, p.ss.x) && !equals(x2, p.ss.x)) || (!equals(yy1, p.ss.y) && !equals(y2, p.ss.y)))){
		}
		else{
			if(vx[i] == 0 || vy[i] == 0) return 1e50;
		}
		double tmpa = p.ss.x - rx[i];
		double tmpb = p.ss.y - ry[i];
		// if(((tmpa >= 0 && vx[i] >= 0) || (tmpa < 0 && vx[i] < 0)) && ((tmpb >= 0 && vy[i] >= 0) || (tmpb < 0 && vy[i] < 0)))
		return d(rx[i], ry[i], p.ss.x, p.ss.y);
	}
	// else if(p.ff == 1 && contains(Point(a, b), Point(c, dd), p.ss)){
	// 	return 0;
	// }
	return 1e50;
}

double findstarttime(int i){
	if(rx[i] > x1 && rx[i] < x2 && ry[i] > yy1 && ry[i] < y2) return 0;

	pair<int, Point> p;
	double mn = 1e50;

	mn = min(mn, getmin(i, x1, yy1, x2, yy1));
	mn = min(mn, getmin(i, x2, yy1, x2, y2));
	mn = min(mn, getmin(i, x2, y2, x1, y2));
	mn = min(mn, getmin(i, x1, y2, x1, yy1));

	mn /= sqrt(vx[i]*vx[i] + vy[i]*vy[i]);

	return mn;
}

double getmax(int i, long long a, long long b, long long c, long long dd){
	pair<int, Point> p;

	p = intersections(Line(Point(rx[i], ry[i]), Point(rx[i]+vx[i], ry[i] + vy[i])),
				      Line(Point(a, b), Point(c, dd)));

	if(p.ff == 1 && contains(Point(a, b), Point(c, dd), p.ss) && ((!equals(x1, p.ss.x) && !equals(x2, p.ss.x)) || (!equals(yy1, p.ss.y) && !equals(y2, p.ss.y)))){
		double tmpa = p.ss.x - rx[i];
		double tmpb = p.ss.y - ry[i];
		// printf("qwe %d %d\n", (tmpa >= 0 && vx[i] >= 0), (tmpa < 0 && vx[i] < 0), );
		if(((tmpa >= 0 && vx[i] >= 0) || (tmpa < 0 && vx[i] < 0)) && ((tmpb >= 0 && vy[i] >= 0) || (tmpb < 0 && vy[i] < 0)))
		return d(rx[i], ry[i], p.ss.x, p.ss.y);
		// else return 1e50;
	}
	else if(p.ff == 1 && contains(Point(a, b), Point(c, dd), p.ss)){
		double tmpa = p.ss.x - rx[i];
		double tmpb = p.ss.y - rx[i];
		if(((tmpa >= 0 && vx[i] >= 0) || (tmpa < 0 && vx[i] < 0)) && ((tmpb >= 0 && vy[i] >= 0) || (tmpb < 0 && vy[i] < 0)))
		return d(rx[i], ry[i], p.ss.x, p.ss.y);
		// else return 1e50;
	}
	// printf("%d %lf %lf %d 1\n", p.ff, p.ss.x, p.ss.y, contains(Point(a, b), Point(c, dd), p.ss));
	return 0;
}

double findendtime(int i){
	pair<int, Point> p;
	double mx = 0;

	mx = max(mx, getmax(i, x1, yy1, x2, yy1));
	mx = max(mx, getmax(i, x2, yy1, x2, y2));
	mx = max(mx, getmax(i, x2, y2, x1, y2));
	mx = max(mx, getmax(i, x1, y2, x1, yy1));

	mx /= sqrt(vx[i]*vx[i] + vy[i]*vy[i]);

	return mx;
}

int main(){

	scanf("%d", &n);

	scanf("%lld %lld %lld %lld", &x1, &yy1, &x2, &y2);

	bool allin = true;

	for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld %lld", rx+i, ry+i, vx+i, vy+i);
		if(rx[i] <= x1 || rx[i] >= x2 || ry[i] <= yy1 || ry[i] >= y2) allin = false;
	}
	if(allin) return printf("0\n"), 0;

	double hi = 1e50, lo = 0;

	for(int i = 0; i < n; i++){
		double mn = findstarttime(i), mx = findendtime(i);
		if(equals(mn, mx)) lo = 1e50;
		lo = max(lo, mn);
		hi = min(hi, mx);
		// printf("%lf %lf %d %d\n", mn, mx);
	}

	if(lo < hi && !equals(lo, hi)) printf("%.20lf\n", lo);
	else printf("-1\n");

	return 0;
}
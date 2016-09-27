#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

bool equals(double a, double b){
	return fabs(a-b) < 1e-9;
}

struct Line {
    double a, b, c;

    Line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

    Line(const pair<double, double>& p, const pair<double, double>& q){
        a = p.ss - q.ss;
        b = q.ff - p.ff;
        c = p.ff * q.ss - p.ss * q.ff;

        double k = a ? a : b;

        a /= k;
        b /= k;
        c /= k;
    }
    bool operator==(const Line& r) const{
        return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
    }
};

pair<int, pair<double, double> > intersections(const Line& r, const Line& s){
    double det = r.a * s.b - r.b * s.a;

    if(equals(det, 0)){
        // Coincidentes ou paralelas
        int qtd = (r == s) ? -1 : 0;

        return mp(qtd, mp(0.0, 0.0)); 
    }
    else{
        // Concorrentes
        double x = (-r.c * s.b + s.c * r.b) / det;
        double y = (-s.c * r.a + r.c * s.a) / det;

        return mp(1, mp(x, y));
    }
}

int main(){

	return 0;
}
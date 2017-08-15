#include <bits/stdc++.h>

using namespace std;

struct cd{
    double r, i;
    cd(double r = 0, double i = 0) : r(r), i(i){}
    double real() const{ return r; }
    void operator*=(double o){ r *= o, i *= o; }
    void operator/=(double o){ r /= o, i /= o; }
    void operator*=(const cd& o){
        double a, b;
        a = r*o.r - i*o.i;
        b = r*o.i + i*o.r;
        r = a, i = b;
    }
    cd operator*(const cd& o) const{ return cd(r*o.r - i*o.i, r*o.i + i*o.r); }
    cd operator+(const cd& o) const{ return cd(r+o.r, i+o.i); }
    cd operator-(const cd& o) const{ return cd(r-o.r, i-o.i); }
};

typedef cd base;

const double PI = acos(-1);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			base w(1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

long long f(long long b, int n, int m){
    long long ans = 1;
    while(n){
        if(n & 1) ans = (ans * b) % m;
        b = (b * b) % m;
        n >>= 1;
    }
    return ans;
}

inline long long cast(double x){ return x; }

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    vector<base> v(1 << (31-__builtin_clz(4*m)));

    vector<long long> ori(v.size());
    for(int i = 1; i < m; i++){
        int x = f(i, n, m);
        ori[x]++;
    }

    for(int i = 0; i < m; i++)
        v[i] = base(ori[i], 0);
    
    fft(v, 0);
    for(int i = 0; i < v.size(); i++)
        v[i] = v[i] * v[i];
    fft(v, 1);

    long long ans = 0;
    
    for(int i = 1; i < m; i++){
        ans += (cast(v[i].real()+0.5) + cast(v[i+m].real()+0.5)) * ori[i];
    }
    
    printf("%lld\n", ans);
}

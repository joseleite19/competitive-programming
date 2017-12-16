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

struct base{
	ll r, i;
	base(ll r = 0, ll i = 0) : r(r), i(i) {}
	base operator*(const base &o){
		return base(r*o.r - i*o.i, r*o.i + o.r*i);
	}
	
	base& operator*=(const base &o){
		double newr = r*o.r - i*o.i, newi = r*o.i + o.r*i;
		r = newr, i = newi;
		return *this;
	}
	
	base& operator+=(const base &o){
		r += o.r, i += o.i;
		return *this;
	}

	base& operator/=(const double &o){
		r /= o, i /= o;
		return *this;
	}
	
	base& operator-=(const base &o){
		r -= o.r, i -= o.i;
		return *this;
	}

	base operator+(const base &o){
		return base(r + o.r, i + o.i);
	}

	base operator-(const base &o){
		return base(r - o.r, i - o.i);
	}	
};


int main(){

	int m, a, b;

	scanf("%d", &m);

	while(m--){
		scanf("%d %d", &a, &b);
		base w(a, b), q(a, b);
		int ans = -1;
		for(int t = 1; t < 300 ; t++){
			if(abs(w.r) > 3e9 || abs(w.i) > 3e9) break;
			if(!w.i){ ans = t; break; }
			w = w * q;
		}

		if(ans == -1) printf("TOO COMPLICATED\n");
		else printf("%d\n", ans);

	}



    return 0;
}

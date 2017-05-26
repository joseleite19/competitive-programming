#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
pair<long long, long long> v[1004];

double det(int i, int j, pair<double, double> p){
	return ;
}

bool is_inside(pair<double, double> p){
	int side = 0;

	for(int i = 0; i+1 < n; i++){
		double d = det(i, i+1, p);
		if(fabs(d) < 1e-9) return true;
		if(side == 0) side = (d > 0);
		else if(side != (d > 0)) return false;
	}
	return true;
}


int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			scanf("%lld %lld", &v[i].ff, &v[i].ss);
		v[n++] = v[0];

		double hi = 1e40, lo = 0;

		for(int i = 0; i < 100; i++){
			double mid = (lo + hi) / 2;

			// calc p

			if(is_inside(p)) lo = mid;
			else hi = mid;
		}
		// calc p
		long long tot = 0;
		for(int i = 0; i+1 < n; i++){

		}
	}
	



	return 0;
}
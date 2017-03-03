#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int t, p, x, y;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d %d", &p, &x, &y);
		p = p;

		x -= 50;
		y -= 50;

		double tmp = atan2(x, y);
		if(tmp < 0) tmp = fabs(tmp) + acos(-1);
		double ang = 2*acos(-1)*p/100;
		if(ang < 0) ang = fabs(ang) + acos(-1);
		printf("Case #%d: %s\n", tc, tmp <= ang+1e-6 && hypot(x, y) <= 50+1e-6 ? "black" : "white");
	}
	
	return 0;
}
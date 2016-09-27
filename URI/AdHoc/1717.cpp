#include <bits/stdc++.h>

#define mp make_pair
#define ff first
#define ss second

using namespace std;

double dp[205][105][3];

int n;

pair<double,double> p[205];

bool mark[205][105][3];

double dist(pair<double,double> p1, pair<double,double> p2){
	return hypot(p1.ff - p2.ff, p1.ss - p2.ss);
}

double f(int v, int groups, int last){
	if(groups == n-1) return 0;
	if(groups > n-1 || v == 2*n-1) return 1e100;

	if(mark[v][groups]) return dp[v][groups];
	mark[v][groups] = 1;

	double ans = 1e100;
	for(int i = v+1; i < 2*n; i++){
		ans = min(ans, dist(p[v], p[i]) + f(i, groups+1));
	}
	ans = min(ans, f(v+1, groups));

	return dp[v][groups] = ans;
}

int main(){	
	scanf("%d", &n);


	for(int i = 0; i < 2*n; i++)
		scanf("%lf %lf", &p[i].ff, &p[i].ss);

	printf("%.4lf\n", f(0, 1));
}
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<int> prices;
vector<double> chances;

double solve(int n, int ind, int c, int money){
	if(money<0)
		return 0.0;
	if(c==0)
		return 1.0;
	if(n>=ind)
		return 0.0;
	return max(1.0*solve(n+1, ind, c, money), max(chances[n]*solve(n+1, ind, c-1, money-prices[n]), (1-chances[n])*solve(n+1, ind, c, money-prices[n]) ));
}

int main(){
	int t, n, c, money, i, p, m;
	scanf(" %d", &t);
	while(t--){
		prices.clear();
		chances.clear();
		scanf(" %d %d %d", &n, &c, &money);
		for(i=0;i<n;i++){
			scanf(" %d %d", &p, &m);
			prices.push_back(p);
			chances.push_back((m*1.0)/100);
		};
		printf("%f\n", solve(0, n, c, money));
	};
	return 0;
}
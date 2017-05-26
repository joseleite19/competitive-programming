#include <bits/stdc++.h>

using namespace std;

char s[1003];

int main(){
	int t, a, b;

	scanf("%d", &t);

	while(t--){
		int n, c;

		scanf("%d %d", &c, &n);

		double d;
		map<string, double> conv;

		for(int i = 0; i < c; i++){
			scanf(" %s %lf", s, &d);
			conv[s] = d;
		}
		conv["JD"] = 1;

		double money = 0;
		for(int i = 0; i < n; i++){
			scanf("%lf %s", &d, s);
			money += conv[s]*d;
		}
		printf("%.6lf\n", money);
	}

	return 0;
}
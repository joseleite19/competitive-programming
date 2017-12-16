#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("bonus.in", "r", stdin);
	// freopen("bonus.out", "w", stdout);

	string s[1001], start;
	int n, a, b;

	cin >> n >> a >> b;
	int qtdA = n-1, qtdB = 0;
	double ans = 0;
	for(int i = 0; i < n; i++, qtdA--, qtdB++){
		double aux = 1;
		for(int j = 0; j < qtdA; j++){
			aux*=(2.00*(a -j)/(2*(a - j) + b + 2));
		}
		for(int j = 0; j < qtdB; j++){
			aux*=(1.0*(b-j)/(2.0*(a - qtdA) + b - j + 2));
		}
		aux *= 2.0/(2*(a - qtdA) + b - qtdB + 2);
		ans += aux;
	printf("%.20lf\n", ans);
	}

	return 0;
}
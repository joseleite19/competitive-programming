#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int main(){
	int t;

	scanf("%d", &t);

	map<int, int> m;
	for(int tc = 1; tc <= t; tc++){
		int n;
		scanf("%d", &n);

		int x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			m[x]++;
		}
	}

	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		if(it->ss <= 3) continue;
		printf("Placa: %04d tem: %d infracoes!%s\n", it->ff, it->ss, (it->ss >= 10) ? " (NINGUEM MERECE)" : "");
	}


	return 0;
}
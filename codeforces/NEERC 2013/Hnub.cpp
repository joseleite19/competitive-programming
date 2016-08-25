#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("hack.in", "r", stdin);
	// freopen("hack.out", "w", stdout);

	vector<int> v;
	vector<vector<int> > m;
	vector<vector<int> > a;
	int n;

	while(scanf("%d", &n) == 1){
		v.assign(n, 0);
		m.assign(n, vector<int>(n));
		a.assign(n, vector<int>(n));
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		long long ans = n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i > j) m[i][j] = a[i][j] = 0;
				else if(i == j) m[i][j] = a[i][j] = v[i];
				else{
					m[i][j] = m[i][j-1] ^ v[j];
					a[i][j] = a[i][j-1] & v[j];
					if(a[i][j] == m[i][j]) ans++;
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%d|%d%c ", m[i][j], a[i][j], m[i][j] == a[i][j] && i <= j ? '*' : ' ');
			}
			printf("\n");
		}
		printf("%lld\n", ans);
	}

	return 0;
}
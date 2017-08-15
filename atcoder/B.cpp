#include <bits/stdc++.h>

using namespace std;

int a[100], b[100], c[100], d[100];
int n, m;

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d %d", a+i, b+i);

	for(int i = 0; i < m; i++)
		scanf("%d %d", c+i, d+i);

	for(int i = 0; i < n; i++){
		int ans = 0, mn = 1000000000;
		for(int j = 0; j < m; j++){
			int dt = abs(a[i] - c[j]) + abs(b[i] - d[j]);
			if(dt < mn){
				mn = dt;
				ans = j;
			}
		}

		printf("%d\n", ans+1);
	}




	return 0;
}
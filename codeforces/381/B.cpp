#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, m, a[200], sum[200];

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);

	sum[0] = 0;

	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + a[i];

	int x, y;
	int ans = 0;
	while(m--){
		scanf("%d %d", &x, &y);
		int tmp = sum[y] - sum[x-1];
		if(tmp > 0) ans += tmp;
	}
	
	printf("%d\n", ans);

	return 0;
}
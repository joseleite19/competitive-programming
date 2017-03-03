#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int main(){
	int n, v[100005];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int mx = 0, mn = 1000000000;

	for(int i = 0; i < n; i++){
		mx = max(mx, v[i]);
		mn = min(mn, v[i]);
	}

	int ans = 0;

	for(int i = 0; i < n; i++)
		if(v[i] != mx && v[i] != mn)
			ans++;

	printf("%d\n", ans);





	return 0;
}
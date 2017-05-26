#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k;

int v[100005];

int main(){
	
	scanf("%d %d", &n, &k);

	int mn = 1000000001;

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	for(int i = 0; i < n; i++)
		mn = min(mn, v[i]);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		int delta = v[i]-mn;
		if(delta % k) return printf("-1\n"), 0;
		ans += delta / k;
	}

	printf("%lld\n", ans);



	return 0;
}
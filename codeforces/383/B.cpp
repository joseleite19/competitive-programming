#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x, a;

	map<int, int> s;

	scanf("%d %d", &n, &x);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);

		ans += s[x^a];

		s[a]++;
	}

	printf("%lld\n", ans);
}
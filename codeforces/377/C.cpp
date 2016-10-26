#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	long long b, d, s;

	scanf("%lld %lld %lld", &b, &d, &s);

	int dx[][3] = {{0, 1, 1}, {0, 0, 1}, {0, 0, 0}, {1, 1, 1}};
	int dy[][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}, {0, 0, 0}};

	long long ans = 2e18;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			long long q = b + dx[i][0] + dy[j][0];
			long long w = d + dx[i][1] + dy[j][1];
			long long e = s + dx[i][2] + dy[j][2];
			long long tmp = max(max(q, w), e);
			ans = min(ans, (tmp - q) + (tmp - w) + (tmp - e));
		}
	}
	printf("%lld\n", ans);

	return 0;
}
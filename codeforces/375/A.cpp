#include <bits/stdc++.h>

#define ss second

using namespace std;

int main(){
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int tmp = (a + b + c) / 3;

	int ans = 1e9;

	for(int i = 0; i < 200; i++){
		tmp = abs(a - i) + abs(b - i) + abs(c - i);
		ans = min(ans, tmp);
	}

	printf("%d\n", ans);

	return 0;
}
#include <bits/stdc++.h>

bool f(int s, int p){
	int i = (s / 50) % 475;
	for(int j = 0; j < 25; j++){
		i = (i * 96 + 42) % 475;
		if(26 + i == p) return true;
	}
	return false;
}

int main(){
	int p, x, y;

	scanf("%d %d %d", &p, &x, &y);

	int ans = -x/50;

	while(x + 50*ans < y || !f(x + 50*ans, p)) ans++;

	printf("%d\n", (std::max(0, ans)+1)/2);

	return 0;
}
#include <bits/stdc++.h>

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(){
	file();
	long long n;

	scanf("%lld", &n);

	int cnt = 0;
	long long tmp = n;
	bool can = true;
	for(long long i = 2; i*i <= n; i++){
		if((n % i) == 0){
			if(((n/i) % i) == 0) can = false;

			cnt++;
			while((n % i) == 0) n /= i;
		}
	}

	if(n > 1) cnt++;

	if(cnt != 3) can = false;

	printf("%s\n", can ? "YES" : "NO");

	return 0;
}
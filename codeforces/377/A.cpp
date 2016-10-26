#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int mdc(int a, int b){
	return b ? mdc(b, a % b) : a;
}

int mmc(int a, int b){
	return a / mdc(a, b) * b;
}

int main(){
	int k, r;

	scanf("%d %d", &k, &r);

	int ans = 1;
	while(1){
		if((ans*k) % 10 == r || (ans*k) % 10 == 0){
			printf("%d\n", ans);
			break;
		}
		ans++;
	}


	return 0;
}
#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

long long n, k, t = 1;
int v[21], lim;

void put(long long n){

	for(int i = 0; n; i++){
		v[i] = n % 10;
		n /= 10;
		lim = i;
	}
	lim++;
}

long long val(int bit){
	long long ans = 0, pot = 1;

	int cnt = 0;
	for(int i = 0; i < 20; i++){
		if(bit & (1 << i)){
			ans += pot*v[i];
			pot *= 10;
			cnt++;
		}
	}

	if(ans == 0 && cnt > 1){
		return 2;
	}
	return ans;
}


int main(){
	
	scanf("%lld %lld", &n, &k);

	for(int i = 0; i < k; i++)
		t *= 10;

	put(n);

	int ans = 1000;
	for(int i = (1 << lim) - 1; i >= 0; i--){
		if(val(i) % t == 0){
			int tmp = 0;
			for(int j = 0; j < lim; j++){
				if(i & (1 << j));
				else
					tmp++;
			}
			ans = min(ans, tmp);
		}
	}

	printf("%d\n", ans);


	return 0;
}
#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, cnt[2048], tmp[2048], k, x;

int main(){

	scanf("%d %d %d", &n, &k, &x);

	for(int i = 0; i < n; i++){
		int u;
		scanf("%d", &u);
		cnt[u]++;
	}

	for(int q = 0; q < k; q++){
		int turn = 1;
		memset(tmp, 0, sizeof tmp);
		for(int i = 0; i < 2048; i++){
			if(cnt[i] & 1){
				int u = cnt[i]/2 + turn;
				tmp[i] += cnt[i] - u;
				tmp[i^x] += u;
			
				turn ^= 1;
			}
			else{
				int u = cnt[i]/2;
				tmp[i] += cnt[i] - u;
				tmp[i^x] += u;
			}
		}

		for(int i = 0; i < 2048; i++)
			cnt[i] = tmp[i];
	}

	int mn, mx;
	for(int i = 0; i < 2048; i++){
		if(cnt[i]){
			mn = i;
			break;
		}
	}

	for(int i = 0; i < 2048; i++){
		if(cnt[i]){
			mx = i;
		}
	}

	printf("%d %d\n", mx, mn);






	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MAXS 11105
#define MAXG 105

int g, c, n, type[105], p[105], s[105], dp[MAXG][MAXS], mat[MAXG][MAXS], change[105];

int main(){
	char aux[50];

	scanf("%d %d %d", &g, &c, &n);

	for(int i = 0; i < n; i++){
		scanf("%s %d %d", aux, p+i, s+i);
		int tmp = g - s[i];
		if(aux[1] == 'r'){
			type[i] = 1;
			change[i] = (tmp / p[i]) * p[i];
		}
		else if(aux[1] == 'o'){
			type[i] = 2;
			int tmp2 = tmp % p[i];
			if(2*tmp2 >= p[i]) change[i] = (1 + tmp / p[i]) * p[i];
			else change[i] = (tmp / p[i]) * p[i];
		}
		else if(aux[1] == 'e'){
			type[i] = 3;
			if(tmp % p[i] == 0) change[i] =  (tmp / p[i]) * p[i];
			else change[i] =  (1 + tmp / p[i]) * p[i];
		}
	}

	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < MAXG; j++){
			for(int k = 0; k < MAXS - change[i]; k++){
				int ans = dp[j][k];
				if(k >= s[i]) ans = max(ans, 1+dp[j][k-s[i]]);
				if(j > 0 && (type[i] != 3 || (k < s[i]))) ans = max(ans, 1+dp[j-1][k + change[i]]);
				mat[j][k] = ans;
			}
		}
		memcpy(dp, mat, sizeof dp);
	}

	printf("%d\n", dp[c][0]);

	return 0;
}
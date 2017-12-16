#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long dp[40][40][40];

long long f(int x, int y, int z){
	if(z < 0) return 0;

	if((x == 0 || y == 0) && z == 0) return 1;
	if(x == 0 || y == 0) return 1;

	long long &ans = dp[x][y][z];

	if(ans != -1) return ans;

	return ans = f(x, y, z - 1) + f(x, y-1, z) + f(x-1, y, z);
}

int main(){

	int a, b, c;

	memset(dp, -1, sizeof dp);

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				printf("%d %d %d: %lld\n", i, j, k, f(i, j, k));
			}
		}
	}



	return 0;
}
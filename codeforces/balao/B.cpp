#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
}

long long dp[100005];
bool mark[100005];

long long f(int n){
	if(mark[n]) return dp[n];
	mark[n] = 1;

	if(n == 0) return dp[n] = 1;
	if(n == 1) return dp[n] = 0;

	return dp[n] = (n-1)*(f(n-1) + f(n-2));
}

int main(){
	long long n;

	scanf("%lld", &n);
	printf("%lld\n",f(n));
	// int id[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> id(n);
	for(int i = 0; i < id.size(); i++)
		id[i] = i;
	
	long long limit = 1LL << (int(id.size()));
	int cnt = 0;
	do{
		for(int j = 0; j < limit; j++){
			bool can = true;
			for(int i = 0; i < (int)id.size(); i++)
				if(j & (1 << i) && id[i] == i)
					can = false;
			if(can) cnt++;
		}
	}while(next_permutation(id.begin(), id.end()));

	printf("%d\n", cnt);

	return 0;
}
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("exchange.in", "r", stdin);
	freopen("exchange.out", "w", stdout);
}

// map<vector<int>, long long> dp;

int num[30];

long long cnt = 0;

long long dp[3][3][3][3][3][3][3][3][3][3][19][2][2];
int mark[3][3][3][3][3][3][3][3][3][3][19][2][2];
int pass;

// long long f(vector<int> left){
// 	cnt++;
// 	if(dp.count(left)) return dp[left];

// 	int j = left[10];

// 	if(j == -1) return 1;

// 	int g = left[11];
// 	int c = left[12];
// 	vector<int> ne = left;
// 	ne[12] = 0;
// 	int ng;
// 	long long ans = 0;
// 	for(int d = c; d < 10; d++){
// 		if(left[d] == 0) continue;
// 		if(!g && num[j] < d) continue;
// 		ng = g;
// 		if(!g && num[j] > d) ng = 1;

// 		ne[d]--;
// 		ne[10] = j-1;
// 		ne[11] = ng;
// 		ans += f(ne);
// 		ne[d]++;
// 	}
// 	return dp[left] = ans;
// }

long long f(int left[]){
	cnt++;
	// if(dp.count(left)) return dp[left];
	int j = left[10];
	if(j == -1) return 1;

	if(mark[ left[0] ][ left[1] ][ left[2] ][ left[3] ][ left[4] ][ left[5] ][ left[6] ][ left[7] ][ left[8] ][ left[9] ][ left[10] ][ left[11] ][ left[12] ] == pass)
		return dp[ left[0] ][ left[1] ][ left[2] ][ left[3] ][ left[4] ][ left[5] ][ left[6] ][ left[7] ][ left[8] ][ left[9] ][ left[10] ][ left[11] ][ left[12] ];
	mark[ left[0] ][ left[1] ][ left[2] ][ left[3] ][ left[4] ][ left[5] ][ left[6] ][ left[7] ][ left[8] ][ left[9] ][ left[10] ][ left[11] ][ left[12] ] = pass;


	int g = left[11];
	int c = left[12];
	// vector<int> ne = left;
	int old10 = left[10];
	// ne[12] = 0;
	left[12] = 0;
	int ng;
	long long ans = 0;
	for(int d = c; d < 10; d++){
		if(left[d] == 0) continue;
		if(!g && num[j] < d) continue;
		ng = g;
		if(!g && num[j] > d) ng = 1;

		left[d]--;
		left[10] = j-1;
		left[11] = ng;
		ans += f(left);
		left[d]++;
	}
	left[10] = old10;
	left[11] = g;
	left[12] = c;
	return dp[ left[0] ][ left[1] ][ left[2] ][ left[3] ][ left[4] ][ left[5] ][ left[6] ][ left[7] ][ left[8] ][ left[9] ][ left[10] ][ left[11] ][ left[12] ] = ans;
}



long long g(long long n){
	// dp.clear();
	int j = 0;
	// memset(dp, -1, sizeof dp);
	memset(num, 0, sizeof num);
	while(n){
		num[j] = n % 10;
		n /= 10;
		j++;
	}

	pass++;

	long long ans = 0;
	int s[13];
	for(int i = 0; i < 10; i++)
		s[i] = 2;
	s[12] = 1;

	// printf("%d\n", j);
	for(int i = 0; i < j; i++){
		s[10] = i;
		s[11] = 1;
		if(i == j-1){
			s[11] = 0;
		}
		// cnt = 0;
		ans += f(s);
		// printf("%lld\n", cnt);
	}
	return ans;
}

int main(){
	long long l, r;

	scanf("%lld %lld", &l, &r);

	printf("%lld\n", g(r) - g(l-1));

	return 0;
}
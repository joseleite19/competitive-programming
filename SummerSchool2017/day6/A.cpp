#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

long long dp[3000][3000];
bool mark[3000][3000];
int r;

long long f(int q2, int q3){
	long long &ans = dp[q2][q3];
	if(q2 < 0 || q3 < 0) return 1000000000000000000;
	if(2*q2 + 3*q3 <= r) return ans = 1;
	// printf("%d %d\n", q2, q3);

	if(mark[q2][q3]) return ans;
	mark[q2][q3] = 1;
	ans = 1000000000000000000;

	for(int i = 0; i <= q2 && 2*i <= r; i++){
		int j = min(q3, (r-2*i)/3);

		ans = min(ans, 1+f(q2-i, q3-j));
	}
	if(ans == 1000000000000000000) ans = 0;

	return ans;
}

int q2 = 0, q3 = 0;

bool f(int mesas){
	if(mesas > q2 + q3) return false;
	if(mesas == q2 + q3) return true;
	if(mesas*r < 2*q2 + 3*q3) return false;

	return true;

	int r1 = r;
	int q = 0, w = 0;
	while(r > 0){
		if(r % 3 == 0){
			r -= 3;
			q++;
		}
		else r -= 2, w++;
	}
}

int main(){
	// file();

	int n;

	scanf("%d %d", &n, &r);


	int x;

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(x & 1){
			q3++;
			q2 += (x-3)/2;
		}
		else{
			q2 += x/2;
		}
	}

	int hi = 100000, lo = 0;

	while(lo + 1 < hi){
		int mid = (lo + hi) / 2;
		if(f(mid)) lo = mid;
		else hi = mid-1;
	}
	if(!f(hi)) hi--;
	printf("%d\n", hi);


	// printf("%lld\n", f(q2, q3));


	return 0;
}
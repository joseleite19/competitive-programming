#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

vector<bool> cnt(500005);
vector<int> p;

long long dp[51][500005];
vector<vector<bool> > mark(51, vector<bool>(500005));

int n;

int v[51];
int qnt[51];

long long f(int i, int j){
	if(i == n){
		// printf("%d %d\n", j, !cnt[j]);
		return !cnt[j];
	}

	if(mark[i][j]) return dp[i][j];
	mark[i][j] = 1;

	long long & ans = dp[i][j];
	ans = 0; 
	for(int q = 1; q <= qnt[i]; q++){
		ans += f(i + qnt[i], j + q*v[i]);
	}
	ans += f(i + qnt[i], j);	

	return ans;

}

int main(){

	int i;
	cnt[0] = cnt[1] = 1;
	for(i = 2; i*i < 500005; i++){
		if(cnt[i]) continue;
		// p.push_back(i);
		for(int j = i*i; j < 500005; j += i)
			cnt[j] = 1;
	}
	// for(; i < 500005; i++)
	// 	if(!cnt[i])
	// 		p.push_back(i);

	// printf("%d\n", p.size());

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	sort(v, v+n);

	for(int i = 0; i < n; i++){
		int j = i;
		while(j < n && v[j] == v[i])j++;
		j--;
		qnt[i] = j - i + 1;
	}

	printf("%lld\n", f(0, 0));






	return 0;
}
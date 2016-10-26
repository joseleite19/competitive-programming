#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int f(int n){
	int ans = 0;
	while(n){
		ans += n%10;
		n /= 10;
	}
	return ans;
}

void file(){
	freopen("digits.in", "r", stdin);
	freopen("digits.out", "w", stdout);
}

int main(){
	file();
	vector< vector<long long> > ans(60);

	int n;

	for(int i = 1; i < 2000000; i++)
		ans[f(i)].push_back(i);

	scanf("%d", &n);
	long long resp = 1e18;
	for(int i = 0; i < 60; i++){
		if(ans[i].size() < n) continue;
		sort(ans[i].begin(), ans[i].end());
		long long tmp = 0;
		for(int j = 0; j < n; j++){
			tmp += ans[i][j];
		}
		resp = min(tmp, resp);
	}
	printf("%lld\n", resp);


}
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int cnt[100005];

int main(){
	int n, x;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}

	int ans = 1;
	for(int i = 2; i < 100005; i++){
		int tmp = 0;
		for(int j = i; j < 100005; j += i){
			tmp += cnt[j];
		}
		ans = max(ans, tmp);
	}

	printf("%d\n", ans);


	return 0;
}
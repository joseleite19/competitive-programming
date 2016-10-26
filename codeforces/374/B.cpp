#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int cnt[200];

int main(){
	int n, k;
	char s[200];

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		cnt[ strlen(s) ]++;
	}
	scanf(" %s", s);
	int pass = strlen(s);

	int ans = 0;

	for(int i = 0; i < pass; i++){
		ans += cnt[i];
	}

	int ans1 = (ans/k)*5 + ans;

	ans += cnt[pass]-1;
	int ans2 = (ans/k)*5 + ans;

	printf("%d %d\n", ans1+1, ans2+1);


	return 0;
}
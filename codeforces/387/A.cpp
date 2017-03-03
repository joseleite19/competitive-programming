#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n;

	scanf("%d", &n);

	int a, b;

	pair<int, int> ans = mp(1, n);

	for(int i = 1; i*i <= n; i++){
		if(n % i == 0){
			pair<int, int> tmp = mp(i, n/i);
			if(tmp.ss - tmp.ff < ans.ss - ans.ff) ans = tmp;
		}
	}

	printf("%d %d\n", ans.ff, ans.ss);


	return 0;
}
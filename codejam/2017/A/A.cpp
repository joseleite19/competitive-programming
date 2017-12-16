#include <bits/stdc++.h>

using namespace std;

char flip(char c){ return c == '+' ? '-' : '+'; }

int main(){

	int t, k, n;
	char s[1003];

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%s %d", s, &k);
		n = strlen(s);
		int ans = 0;
		
		for(int i = 0; i <= n-k; i++){
			if(s[i] == '-'){
				ans++;
				for(int j = 0; j < k; j++)
					s[i+j] = flip(s[i+j]);
			}
		}

		for(int i = 0; i < n; i++)
			if(s[i] == '-')
				ans = -1;

		printf("Case #%d: ", tc);
		if(ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}

	return 0;
}
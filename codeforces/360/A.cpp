#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, d, ans;
	char c;
	ans = 0;

	scanf("%d %d", &n, &d);
	int tmp = 0;
	for(int i = 0; i < d; i++){
		bool beat = false;
		for(int i = 0; i < n; i++){
			scanf(" %c", &c);
			if(c == '0')
				beat = true;
		}
		if(beat) tmp++;
		else{
			ans = max(ans, tmp);
			tmp = 0;
		}
	}
	ans = max(ans, tmp);
	printf("%d\n", ans);
}

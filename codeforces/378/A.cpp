#include <bits/stdc++.h>

int main(){
	char s[10000];

	scanf("%s", s);

	int ans = -1;
	int last = -1;
	int i;
	for(i = 0; s[i]; i++){
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
			ans = std::max(ans, i - last);

			last = i;
		}
	}
	ans = std::max(ans, i - last);

	printf("%d\n", ans);

}
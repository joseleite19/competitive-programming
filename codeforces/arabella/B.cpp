#include <bits/stdc++.h>

int main(){
	int t, a, b;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &a, &b);
		if(a >= b) printf("FunkyMonkeys\n");
		else printf("WeWillEatYou\n");
	}

	return 0;
}
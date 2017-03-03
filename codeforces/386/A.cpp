#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int ans = 0;

	for(int i = 0; i <= a; i++){
		if(2*i <= b && 4*i <= c){
			ans = max(ans, 7*i);
		}
	}

	printf("%d\n", ans);


	return 0;
}
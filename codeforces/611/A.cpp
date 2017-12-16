#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
char s[100];

int main(){

	scanf("%d of %s", &n, s);

	int ans = 0;
	if(s[0] == 'm'){
		if(n <= 29) ans = 12;
		else if(n == 30) ans = 11;
		else ans = 7;
	}
	else{
		// 4 = 52

		if(n == 7) ans = 52;
		else if(n == 6 || n == 5) ans = 53;
		else ans = 52;
	}

	printf("%d\n", ans);

	return 0;
}
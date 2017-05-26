#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char s[30];

int main(){

	scanf("%s", s);
	int n = strlen(s);

	int diff = 0;
	for(int i = 0; i < n/2; i++)
		if(s[i] != s[n-1-i])
			diff++;

	if(diff >= 2) return printf("NO\n"), 0;

	if(diff == 1) return printf("YES\n"), 0;

	if(n & 1) printf("YES\n");
	else printf("NO\n");



	return 0;
}
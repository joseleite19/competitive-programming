#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, a, b;
	char s[100005];

	scanf("%d %d %d %s", &n, &a, &b, s);
	a--; b--;

	printf("%d\n", s[a] != s[b]);

	return 0;
}
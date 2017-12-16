#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("concatenation.in", "r", stdin);
	freopen("concatenation.out", "w", stdout);
}

long long p[26], s[26];
int main(){
	file();

	char pre[100005], suf[100005];

	scanf(" %s %s", pre, suf);
	int i;
	for(i = 1; pre[i]; i++)
		p[ pre[i]-'a' ]++;

	long long n = i;

	for(i = 0; suf[i+1]; i++)
		s[ suf[i]-'a' ]++;

	long long m = i+1;

	long long ans = n * m;

	for(int i = 0; i < 26; i++)
		ans -= p[i]*s[i];

	printf("%lld\n", ans);

	return 0;
}
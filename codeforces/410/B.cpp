#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;

char s[100][100];

int tmp[100];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf(" %s", s[i]);

	int sz = strlen(s[0]);

	for(int i = 0; i < n; i++)
		if(strlen(s[i]) != sz)
			return printf("-1\n"), 0;

	string target = s[0];
	target += s[0];
	for(int i = 0; i < n; i++){
		tmp[i] = target.find(s[i]);
		if(tmp[i] == string::npos) return printf("-1\n"), 0;
		printf("|%d\n", tmp[i]);
	}

	int ans = 1000000000;
	for(int start = 0; start < sz; start++){
		int q = 0;
		for(int i = 0; i < n; i++){
			if(start >= tmp[i]) q += start - tmp[i];
			else q += sz - tmp[i] + start;
		}
		printf("%d\n", q);
		ans = min(ans, q);
	}

	printf("%d\n", ans);





	return 0;
}
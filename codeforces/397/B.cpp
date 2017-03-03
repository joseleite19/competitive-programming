#include <bits/stdc++.h>

using namespace std;

int cnt[256];
int first[256];

int main(){
	int n;
	char s[1000];

	scanf("%s", s);
	n = strlen(s);

	int last = 0;
	memset(first, -1, sizeof first);

	for(int i = 0; i < n; i++){
		cnt[ s[i] ]++;
		last = max(last, (int)s[i]);
		if(first[ s[i] ] == -1)
			first[ s[i] ] = i;
	}

	bool can = true;
	for(int i = 'a'; i <= last; i++)
		if(!cnt[i])
			can = false;

	for(int i = 'a'; i < last; i++){
		if(first[i] > first[i+1])
			can = false;
	}

	printf("%s\n", can ? "YES" : "NO");
}
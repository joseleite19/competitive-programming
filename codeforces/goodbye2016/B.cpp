#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, t, pos = 0;

	char s[100];

	scanf("%d", &n);

	bool valid = 1;
	for(int i = 0; i < n; i++){
		scanf("%d %s", &t, s);
		if(s[0] == 'E' || s[0] == 'W'){
			if(pos == 0 || pos == 20000) valid = 0;
			continue;
		}
		if(s[0] == 'N') pos -= t;
		if(s[0] == 'S') pos += t;
		if(pos < 0 || pos > 20000) valid = 0;
	}
	if(pos) valid = 0;

	printf("%s\n", valid ? "YES" : "NO");

	return 0;
}
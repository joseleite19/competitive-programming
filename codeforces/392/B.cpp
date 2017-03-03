#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
char s[200];
int f(int &cnt, char c){
	int i = 0;
	for(i = 0; i < n; i++){
		if(s[i] == c)
			break;
	}
	while(i - 4 >= 0) i -= 4;
	for(; i < n; i += 4)
		if(s[i] != c)
			cnt++;
}

int main(){

	scanf("%s", s);

	n = strlen(s);

	int r, b, y, g;
	r = b = y = g = 0;

	f(r, 'R');
	f(b, 'B');
	f(y, 'Y');
	f(g, 'G');

	printf("%d %d %d %d\n", r, b, y, g);

	return 0;
}
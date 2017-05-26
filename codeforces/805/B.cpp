#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char s[200005];

int main(){
	int n;

	scanf("%d", &n);

	if(n == 1) return printf("a\n"), 0;
	if(n == 2) return printf("aa\n"), 0;

	int cnt = 0, c = 0;
	for(int i = 0; i < n; i++){
		s[i] = 'a'+c;
		cnt++;
		if(cnt == 2){
			cnt = 0;
			c ^= 1;
		}
	}
	s[n] = 0;

	printf("%s\n", s);


	return 0;
}
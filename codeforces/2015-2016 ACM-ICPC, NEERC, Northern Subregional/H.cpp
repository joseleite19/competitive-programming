#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
}

int exp(int b, int e){
	int ans = 1;
	while(e){
		if(e & 1) ans *= b;
		b *= b;
		e >>= 1;
	}
	return ans;
}

int hash(char *s){
	int n = strlen(s);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += s[i]*exp(31, n-1-i);
	return ans;
}

int main(){
	file();

	char s[1001];
	int k;

	memset(s, 'm', sizeof s);
	s[1000] = '\0';

	scanf("%d", &k);

	printf("%s\n", s);
	for(int i = 0; i < k-1; i++){
		s[i]++;
		s[i+1] -= 31;
		printf("%s\n", s);
		s[i]--;
		s[i+1] += 31;
	}

	return 0;
}
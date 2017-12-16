#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)

using namespace std;

typedef long long ll;
const int N = 10000;

char s[N];
char t[N];

int proc(){
	int ans = 0;
	int n = strlen(s), j = 0;
	forn(i, n){
		if(s[i] == 'k' && s[i+1] == 'h'){
			t[j++] = 'h';
			i++;
			ans = 1;
		}
		else if(s[i] == 'u'){
			t[j++] = 'o';
			t[j++] = 'o';
			ans = 1;
		}
		else t[j++] = s[i];
	}
	t[j] = 0;
	strcpy(s, t);
	return ans;
}

int main(){

	set<string> ss;
	int n;

	scanf("%d", &n);

	forn(i, n){
		scanf(" %s", s);
		while(proc());
		ss.insert(s);
	}
	
	printf("%d\n", int(ss.size()));




}


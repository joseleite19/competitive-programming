#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

char s[N];

int main(){

	while(scanf(" %s", s) == 1 && strcmp(s, "0")){
		int n = strlen(s);
		int a = 0, b = 0;
		forn(i, n){
			if(i & 1) a += s[i] - '0';
			else b += s[i] - '0';
		}
		a = (a - b) % 11;
		if(!a) printf("%s is a multiple of 11.\n", s);
		else printf("%s is not a multiple of 11.\n", s);
	}



    return 0;
}

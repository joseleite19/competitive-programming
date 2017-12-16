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

int comp(int x){
	int ans = 0;
	while(x) ans += x % 10, x /= 10;
	return ans;
}

int f(int x){
	if(!x || x == 9) return 0;
	return 1 + f(comp(x));
}

int main(){

	while(scanf(" %s", s) == 1 && strcmp(s, "0")){
		int n = strlen(s), a = 0;
		forn(i, n) a += s[i] - '0';
		if(a % 9) printf("%s is not a multiple of 9.\n", s);
		else{
			printf("%s is a multiple of 9 and has 9-degree %d.\n", s, f(a)+1);
		}
	}


    return 0;
}

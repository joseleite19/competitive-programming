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

int n;
char s[N];

int main(){

	scanf("%s", s);

	n = strlen(s);

	int zero = 0, one = 0;
	forn(i, n){
		if(one) zero += s[i] == '0';
		if(s[i] == '1') one = 1;
	}

	printf("%s\n", zero >= 6 ? "yes" : "no");


    return 0;
}

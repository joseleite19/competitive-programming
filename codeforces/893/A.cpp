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


int main(){

	int s;
	int n;

	s = 3;
	scanf("%d", &n);

	int x;
	forn(i, n){
		scanf("%d", &x);
		x--;
		if(!(s & (1 << x))) return printf("NO\n"), 0;
		s = ~s & 7;
		s |= 1 << x;
	}
	printf("YES\n");


    return 0;
}

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

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int d;
	for(int i = 1; i < 10000000; i++){
		a *= 10;
		d = a / b;
		if(c == d) return printf("%d\n", i), 0;
		a %= b;
	}

	printf("-1\n");



    return 0;
}

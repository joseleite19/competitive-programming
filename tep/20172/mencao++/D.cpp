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

int v[3], w[3];

int main(){

	int n;

	scanf("%d", &n);

	while(n--){
		forn(i, 3) scanf("%d", w+i), v[i] += w[i];
	}

	printf("%s\n", !v[0] && !v[1] && !v[2] ? "YES" : "NO");



    return 0;
}

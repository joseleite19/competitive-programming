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

void file(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
}

int p[N], v[N], t[N];
char s[N][8];

int main(){
	file();

	int n, x;

	scanf("%d", &n);

	fore(i, 1, n+1){
		scanf("%d", &x);
		p[x] = i;
		v[i] = i;
	}

	fore(i, 1, n+1) scanf(" %s", s[i]); 

	forn(k, 3){
		fore(i, 1, n+1) t[ p[i] ] = v[i];
		memcpy(v+1, t+1, n*sizeof(int));
	}

	fore(i, 1, n+1)
		printf("%s\n", s[ v[i] ]);

    return 0;
}

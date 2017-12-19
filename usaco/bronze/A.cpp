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

const int N = 2500;
const int M = 1005;

void file(){
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
}

int mat[N][N];

int main(){
	file();

	int a, b, c, d;

	forn(k, 2){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		fore(i, a, c) fore(j, b, d){
			mat[i+M][j+M] = 1;
		}
	}

	scanf("%d %d %d %d", &a, &b, &c, &d);
	fore(i, a, c) fore(j, b, d){
		mat[i+M][j+M] = 0;
	}

	int ans = 0;

	forn(i, N) forn(j, N) ans += mat[i][j];

	printf("%d\n", ans);



    return 0;
}

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

char mat[10][10];

int main(){

	forn(i, 8) scanf(" %s", mat[i]);

	int ans = 0;
	forn(i, 8){
		int t = 1;
		forn(j, 8) t &= mat[i][j] == 'B';
		ans += t;
	}

	if(ans < 8){
		forn(j, 8){
			int t = 1;
			forn(i, 8) t &= mat[i][j] == 'B';
			ans += t;
		}
	}

	printf("%d\n", ans);

    return 0;
}

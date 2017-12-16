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
typedef pair<int, int> ii;
const int N = 105;

char mat[N][N];

int n;
ii dp[N][N][2];

ii operator+(ii a, ii b){
	return ii(a.ff + b.ff, a.ss + b.ss);
}

ii f(int i, int j, int p){
	ii ret(0, 0);
	if(i >= n || j >= n) return ii(p?1000000000:0, p?0:1000000000);
	if(i == n-1 && j == n-1){
		if(mat[i][j] == 'a') ret.ff++;
		else if(mat[i][j] == 'b') ret.ss++;
		return ret;
	}

	//if(~dp[i][j][p].ff) return dp[i][j][p];

	ii a = f(i+1, j, p^1);
	ii b = f(i, j+1, p^1);

	if(p){
		if(a.ff - a.ss > b.ff - b.ss) ret = a;
		else ret = b;
	}
	else{
		if(a.ss - a.ff > b.ss - b.ff) ret = a;
		else ret = b;
	}
	return dp[i][j][p] = ret + ii(mat[i][j]=='a', mat[i][j]=='b');
}

int main(){

	scanf("%d", &n);

	forn(i, n) scanf(" %s", mat[i]);

	memset(dp, -1, sizeof dp);

	int t = f(0, 0, 0).ff - f(0, 0, 0).ss;

	if(t > 0) printf("FIRST\n");
	else if(t < 0) printf("SECOND\n");
	else printf("DRAW\n");



    return 0;
}

#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define debug(x) cout << #x << " = " << x << endl
#define ford(i, a, b) for(int i = int(a); i >= int(b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 100005;

const int MAX = 1e6 + 6;
const int MOD = 1e9 + 7;
int memo[MAX][2][2];

inline int add(int a, int b) {
	a += b;
	if(a >= MOD) {
		a -= MOD;
	}
	return a;
}

int roll(int len, int a, int c) {
	if(len == 0) {
		return a == 0 || c == 1;
	}
	int &ans = memo[len][a][c];
	if(~ans) {
		return ans;
	}
	ans = (2 * roll(len - 1, a, c)) % MOD;
	ans = add(ans, roll(len - 1, (a + 1) & 1, c));
	ans = add(ans, roll(len - 1, a, (c + 1) & 1));
	return ans;
}

int main(){
	memset(memo, -1, sizeof memo);
	fori(i, 0, MAX) {
		fori(j, 0, 2) {
			fori(k, 0, 2) {
				roll(i, j, k);
			}
		}
	}
	int kase = 1;
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("Caso #%d: %d\n", kase++, roll(n, 0, 0));
	}

    return 0;
}

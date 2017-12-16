#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 1005;

int n, a[4];

char s[4][N];

//0 4  8
//1 5  9
//2 6 10
//3 7 11

inline int ml(int i){
	int ans = 0;
	forn(j, 4) ans |= (s[j][i] << j);
	return ans;
}

vector<int> v;

inline int index(int x){
	if(x == 1) return 0;
	if(x == 4) return 1;
	if(x == 9) return 2;
	if(x ==16) return 3;
	assert(0);
}

int dp[N][1 << 12];

int f(int i, int bit){
	int &ans = dp[i][bit];
	if(~ans) return ans;
	ans = 1000000000;

	if(i == n && !bit) return ans = 0;

	int mbit = bit | (ml(i) << 12), nbit, id;

	if((mbit & 15) == 0) ans = min(ans, f(min(n, i+1), mbit >> 4));
	forn(j, v.size()){
		nbit = mbit & ~v[j];
		id = index(__builtin_popcount(v[j]));
		if(nbit == mbit) continue;
		if(nbit	& 15) ans = min(ans, a[id] + f(i, nbit & ~0xf000));
		else ans = min(ans, a[id] + f(min(n, i+1), nbit >> 4));
	}

	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);

	scanf("%d", &n);

	forn(j, 4) scanf("%d", a+j);
	forn(j, 4) scanf(" %s", s[j]);

	forn(j, 4) forn(i, n) s[j][i] = s[j][i] == '*';

	v.pb(0x1), v.pb(0x2), v.pb(0x4), v.pb(0x8);
	v.pb(0x33), v.pb(0x66), v.pb(0xcc);
	v.pb(0x777), v.pb(0xeee);
	v.pb(0xffff);

	printf("%d\n", f(3, ml(0) | (ml(1) << 4) | (ml(2) << 8)));

    return 0;
}

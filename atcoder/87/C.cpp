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

	int n, x;
	map<int, int> cnt;

	scanf("%d", &n);

	forn(i, n) scanf("%d", &x), cnt[x]++;

	int ans = 0;

	for(auto w : cnt){
		if(w.ff > w.ss) ans += w.ss;
		else ans += w.ss - w.ff;
	}
	printf("%d\n", ans);


    return 0;
}

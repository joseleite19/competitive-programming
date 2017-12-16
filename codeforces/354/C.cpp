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

const int N = 1000006;

int n, k, x;

set<int>::iterator t[N];

int main(){

	scanf("%d %d", &n, &k);

	set<int> s;

	forn(i, n) scanf("%d", &x), s.insert(x);

	int ans = 1;

	for(int i = 1; i < N; i++)
		t[i] = s.upper_bound(i+k);

	for(int i = 1; i < N; i++){
		set<int>::iterator it = s.begin();
		int can = 1;
		for(int j = i; j < N; j += i){
			if(*it < j){ can = 0; break; }
			it = t[j];
			if(it == s.end()) break;
		}
		if(it != s.end()) can = 0;
		if(can) ans = max(ans, i);
	}

	printf("%d\n", ans);

    return 0;
}

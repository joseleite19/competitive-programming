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

int n, v[N], d;

int main(){

	int ans = 0;

	scanf("%d %d", &n, &d);

	forn(i, n) scanf("%d", v+i);

	forn(i, n) forn(j, n) if(i != j){
		if(abs(v[i] - v[j]) <= d)
			ans++;
	}

	printf("%d\n", ans);



    return 0;
}

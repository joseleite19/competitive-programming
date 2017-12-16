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

int n, v[N];

int main(){

	scanf("%d", &n);

	forn(i, n) scanf("%d", v+i);

	int ans = 0;
	fore(i, 1, n-1)
		ans += (v[i-1] < v[i] && v[i] > v[i+1]) ||
		 	   (v[i-1] > v[i] && v[i] < v[i+1]);
	
	printf("%d\n", ans);

    return 0;
}

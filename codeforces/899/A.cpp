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

int v[100];
int main(){
	int n, a = 0, b = 0;

	scanf("%d", &n);

	int x;
	while(n--) scanf("%d", &x), v[x]++;

	int ans = min(v[1], v[2]);

	v[1] -= ans, v[2] -= ans;

	ans += v[1] / 3;

	printf("%d\n", ans);



    return 0;
}

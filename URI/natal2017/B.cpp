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

	int n;
	ll x;

	scanf("%d", &n);

	while(n--){
		scanf("%lld", &x);
		int ans = 0, t = 0;
		while(x){
			if(x & 1) t++;
			else ans = max(ans, t), t = 0;
			x /= 2;
		}
		ans = max(ans, t);
		printf("%d\n", ans);
	}


    return 0;
}

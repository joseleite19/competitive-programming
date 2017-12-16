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

int n;

bool f(ll x){
	if(x == 1) return false;
	ll w = sqrt(x);

	ll e;
	for(ll i = max(0LL, w - 5); i <= w + 5; i++)
		if(i * i == x){
			for(e = 2; e*e <= i; e++){
				if(i % e == 0) return false;
			}
			return true;
		}
	return false;
}

int main(){
	
	ll x;

	scanf("%d", &n);

	while(n--){
		scanf("%lld", &x);
		printf("%s\n", f(x) ? "YES" : "NO");
	}



    return 0;
}

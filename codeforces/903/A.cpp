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

bool can(int x){
	for(int i = 0; i < 100; i++){
		if(x >= 3 * i && (x - 3*i) % 7 == 0) return 1;
	}
	return 0;
}

int main(){
	int n, x;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &x);
		printf("%s\n", can(x) ? "YES" : "NO");
	}



    return 0;
}

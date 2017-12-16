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

int is_prime(int x){
	int ans = 0;
	for(int i = 1; i <= x; i++)
		ans += x % i == 0;
	return ans == 2;
}

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	n++;
	while(!is_prime(n)) n++;

	printf("%s\n", n == m ? "YES" : "NO");



    return 0;
}

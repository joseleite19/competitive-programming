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
	int a = 0, b = 0;

	int n;

	int x, y;

	scanf("%d", &n);

	while(n--){
		scanf("%d %*d", &x);
		if(x > 0) a++;
		else b++;
	}

	printf("%s\n", a <= 1 || b <= 1 ? "YES" : "NO");


    return 0;
}

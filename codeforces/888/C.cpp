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
char s[N];

int f(char c){
	int last = -1;
	int ans = 1;
	forn(i, n){
		if(s[i] != c) continue;
		ans = max(ans, i - last);
		last = i;
	}
	ans = max(ans, n - last);
	return ans;
}

int main(){
	scanf("%s", s);

	n = strlen(s);

	int ans = 1e9;
	fore(i, 'a', 'z'+1) ans = min(ans, f(i));

	printf("%d\n", ans);



    return 0;
}

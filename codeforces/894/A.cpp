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

char s[N];
int n;

int main(){

	scanf("%s", s);

	n = strlen(s);

	int ans = 0;
	forn(i, n) if(s[i] == 'Q'){
		fore(j, i+1, n) if(s[j] == 'A'){
			fore(k, j+1, n) if(s[k] == 'Q')
				ans++;
		}
	}

	printf("%d\n", ans);

    return 0;
}

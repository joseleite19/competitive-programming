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

char s[N], t[N];

int main(){

	int T;

	scanf("%d%*c", &T);

	while(T--){
		scanf("%[^\n]%*c", s);
		scanf("%[^\n]%*c", t);
		int n = strlen(s), m = strlen(t);
		for(int i = 0; i < n; i += 2){
			printf("%c%c", s[i], s[i+1]);
			printf("%c", t[i]);
			if(i+1 < m) printf("%c", t[i+1]);
		}
		printf("\n");
	}


    return 0;
}

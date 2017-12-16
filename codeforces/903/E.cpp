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

const int N = 5005;

int n, k;

char s[N/2][N];

int mis[N];

int main(){

	scanf("%d %d", &k, &n);

	forn(i, k) scanf(" %s", s[i]);

	bool rep = 0;

	map<char, int> tmp;
	forn(i, n) rep |= tmp[ s[0][i] ], tmp[ s[0][i] ]++;

	fore(i, 1, k){
		map<char, int> t;
		forn(j, n) mis[i] += s[0][j] != s[i][j], t[ s[i][j] ]++;
		if(tmp != t) return printf("-1\n"), 0;
	}

	int x = 0;
	forn(i, n){
		fore(j, i+1, n){
			bool ok = 1;
			fore(l, 1, k){
				x = 0;
				if(s[0][i] != s[l][i]){
					if(s[0][j] == s[l][i])
						x--;
				}
				else if(s[0][j] != s[l][i]) x++;
				if(s[0][j] != s[l][j]){
					if(s[0][i] == s[l][j])
						x--;
				}
				else if(s[0][i] != s[l][j]) x++;
				if(rep){
					if(mis[l] + x != 0 && mis[l] + x != 2){
						ok = 0;
						break;
					}
				}
				else if(mis[l] + x != 2){
					ok = 0;
					break;
				}
			}
			if(ok){
				swap(s[0][i], s[0][j]);
				printf("%s\n", s[0]);
				return 0;
			}
		}
	}

	printf("-1\n");


    return 0;
}

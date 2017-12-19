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

int v[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int v2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n, a[N];

bool solve(){
	int id = -1;

	forn(i, n) if(a[i] == 29) id = i;

	if(id == -1){
		forn(off, 12){
			bool ok = 1;
			forn(i, n) if(v[off+i] != a[i]){
				ok = 0;
				break;
			}
			if(ok) return 1;
		}
	}
	else{
		int j = 1;
		bool t = 0;
		for(int i = id; i < n; i++){
			if(j == 12) j = 0, t = 1;
			if(t){
				if(v[j] != a[i]) return 0;
			}
			else if(v2[j] != a[i]) return 0;
			j++;
		}
		t = 0, j = 1;
		for(int i = id; i >= 0; i--){
			if(j == -1) j = 11, t = 1;
			if(t){
				if(v[j] != a[i]) return 0;
			}
			else if(v2[j] != a[i]) return 0;
			j--;
		}
		return 1;
	}

	return 0;
}

int main(){

	scanf("%d", &n);

	forn(i, n) scanf("%d", a+i);

	printf("%s\n", solve() ? "YES" : "NO");



    return 0;
}

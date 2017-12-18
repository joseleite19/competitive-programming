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

const int N = 100050;

char s[N];
map<char, int> tr[24*N];
int cnt[24*N];
int p = 1;

void add(char *st){
	int ptr = 0;
	for(int i = 0; st[i]; i++){
		if(!tr[ptr].count(st[i])) tr[ptr][ st[i] ] = p++;
		ptr = tr[ptr][ st[i] ];
		cnt[ptr]++;
	}
}

int search(char *st){
	int ptr = 0;
	for(int i = 0; st[i]; i++){
		if(!tr[ptr].count(st[i])) return 0;
		ptr = tr[ptr][ st[i] ];
	}
	return cnt[ptr];
}

int main(){
	int n;

	scanf("%d", &n);

	while(n--){
		scanf(" %[^\n]", s);
		if(s[0] == 'a') add(s+4);
		else printf("%d\n", search(s+5));
	}



    return 0;
}

#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 105;

char s[N][N];

int n, m;

void fall(int i, int j){
    while(i+1 < n && s[i+1][j] == '.'){
        swap(s[i+1][j], s[i][j]);
        i++;
    }
}

int main(){

    scanf("%d %d", &n, &m);

    forn(i, n) scanf(" %s", s[i]);

    ford(i, n) forn(j, m) if(s[i][j] == 'o')
        fall(i, j);

    forn(i, n) printf("%s\n", s[i]);


    return 0;
}

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
const int N = 100005;

char s[10][10];

int f(char c){
    if(c == 'q') return 9;
    if(c == 'r') return 5;
    if(c == 'b') return 3;
    if(c == 'n') return 3;
    if(c == 'p') return 1;
    return 0;
}

int main(){

    forn(i, 8) scanf(" %s", s[i]);

    int a = 0, b = 0;
    forn(i, 8) forn(j, 8){
        if(s[i][j] >= 'a' && s[i][j] <= 'z') a += f(s[i][j]);
        else b += f(tolower(s[i][j]));
    }

    if(a < b) printf("White\n");
    else if(b < a) printf("Black\n");
    else printf("Draw\n");



    return 0;
}

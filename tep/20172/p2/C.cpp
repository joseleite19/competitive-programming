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
const int N = 1005;

char s[N];

int vogal(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

ll fat[N];
int cnt[N];
int main(){

    int n;

    scanf("%d", &n);

    if(n == 1) return printf("0\n"), 0;

    int a = 0, b = 0;

    fat[0] = 1;
    for1(i, 30) fat[i] = i*fat[i-1];


    forn(i, n){
        scanf("%s", s);
        a += vogal(s[0]), b += !vogal(s[0]);
        cnt[ tolower(s[0]) ]++;
    }

    ll ans = fat[n-2] * a * b;

    forn(i, N)
        ans /= fat[ cnt[i] ];

    printf("%lld\n", ans);




    return 0;
}

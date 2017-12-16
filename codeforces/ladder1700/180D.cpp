#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
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

char s[N], t[N];

int cnt[256], n, m;

bool f(int i){
    if(i == n) return 1;
    if(i == m){
        int j = 'a';
        for(; i < n; i++){
            while(j <= 'z' && !cnt[j]) j++;
            s[i] = j;
            cnt[j]--;
        }
        return 1;
    }

    int j = t[i];
    while(j <= 'z' && !cnt[j]) j++;
    if(j > 'z') return 0;


    if(j == t[i]){
        s[i] = j;
        cnt[j]--;
        if(f(i+1)) return 1;
        cnt[j]++;
        j++;
        while(j <= 'z' && !cnt[j]) j++;
        if(j > 'z') return 0;
    }
    s[i] = j;
    cnt[j]--;

    j = 'a';
    for(i++; i < n; i++){
        while(j <= 'z' && !cnt[j]) j++;
        s[i] = j;
        cnt[j]--;
    }
    //printf("%d %c %d %s\n", i, j, n, s);
    //if(j > 'z')

    return 1;
}

int main(){

    scanf(" %s %s", s, t);
    n = strlen(s), m = strlen(t);

    if(n == m && n == 1){
        if(s[0] <= t[0]) printf("-1\n");
        else printf("%s\n", s);
        return 0;
    }

    forn(i, n) cnt[ s[i] ]++;

    bool gt = 0;

    if(!f(0)) return printf("-1\n"), 0;

    if(n <= m){
        forn(i, n) if(s[i] != t[i]) gt = 1;
    }
    else gt = 1;

    if(!gt){
        if(!next_permutation(s, s+n)) return printf("-1\n"), 0;
    }

    printf("%s\n", s);



    return 0;
}

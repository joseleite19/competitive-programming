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
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

char s[N];
int n;

int ask(){
    printf("? %s\n", s); fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int tot;
bool f(int mid){
    for1(i, n-1) s[i] = s[n+1];
    for1(i, mid) s[i] = s[0];
    int x = ask();
    if(x == tot) return 1;
    if(x < 
}

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        s[i] = '0';

    int x = ask();

    s[0] = '1';

    int xx = ask();
    int p0, p1;
    p0 = p1 = -1;
    if(x < xx){
        p0 = 0;
        s[0] = '0';
        s[n+1] = '1';
        tot = n - xx;
    }
    else{
        p1 = 0;
        s[0] = '1';
        s[n+1] = '0';
        tot = n - x;
    }

    int lo = 0, hi = n-2;

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        for(int i = 1; i < n; i++) s[i] = s[n+1];
        for(int i = 1; i <= mid; i++)
            s[i] = s[0];
        int x = ask();
        if(x - tot >= mid-1) hi = mid-1;
        else lo = mid;
    }
    for1(i, n-1) s[i] = s[n+1];
    for1(i, lo) s[i] = s[0];
    if(ask() - tot >= lo-1) hi = lo;

    if(p0 == -1) p0 = hi+1;
    else p1 = hi+1;

    printf("! %d %d\n", p0+1, p1+1);
    fflush(stdout);


    return 0;
}

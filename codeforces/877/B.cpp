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

int a[N], b[N];

char s[N];

int main(){

    scanf("%s", s);

    int n = strlen(s);

    for1(i, n) if(s[i-1] == 'a') a[i]++;
               else b[i]++;

    for1(i, n) a[i] += a[i-1], b[i] += b[i-1];

    int ans = 0;
    forn(i, n+1) fore(j, i+1, n+1){
        //[1, i] | [i, j-1], [j, n]
        ans = max(ans, a[i] + (b[j-1] - (i ? b[i-1] : 0)) + a[n] - a[j-1]);
    }
    printf("%d\n", ans);


    return 0;
}

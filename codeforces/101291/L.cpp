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

bool f(int a, int b, int c, int d, int base) {
    bool ans = false;
    if(a == b) {
        if(c == base)
            ans |= (a + d == base);
        if(d == base)
            ans |= (a + c == base);
    }

    return ans;
}

int main(){
    int a[3], b[3];

    for(int i = 0; i < 3; i++) {
        scanf("%d%d", &a[i], &b[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
    }

    bool ans = false;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) continue;
            for(int k = 0; k < 3; k++) {
                if(i == k or j == k) continue;
                ans |= f(a[i], a[j], a[k], b[k], b[i]+b[j]);
                ans |= f(b[i], a[j], a[k], b[k], a[i]+b[j]);
                ans |= f(a[i], b[j], a[k], b[k], b[i]+a[j]);
                ans |= f(b[i], b[j], a[k], b[k], a[i]+a[j]);

                if(b[i] == b[j] and b[j] == b[k]) {
                    ans |= (b[i] == a[i] + a[j] + a[k]);
                }
            }
        }
    }
    
    printf("%s\n", (ans ? "YES" : "NO"));





    return 0;
}


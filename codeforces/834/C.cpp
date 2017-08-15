#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 1006;

int lp[N];

/*int p(int n) {
    if((n & 1) == 0) return 2;
    srand(time(NULL)); 
    int x, y, g = 1, a;
    x = rand() % n + 1;
    y = x;
    a = rand() % n + 1;
    while(g == 1) {
        x = ((1LL*x*x) + a)%n;  
        y = ((1LL*y*y) + a)%n;
        y = ((1LL*y*y) + a)%n;  
        g = __gcd(abs(x - y), n);
    }
    return g;
}*/

inline long long mul(long long a, long long b, long long mod){
    return (a * b) % mod;
}
long long pollard_rho(long long n, long long c) {
    long long x = 2, y = 2, i = 1, k = 2, d;
    while (true) {
        x = (mul(x, x, n) + c);
        if (x >= n) x -= n;
        d = __gcd(abs(x - y), n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

long long llgcd(long long x, long long y) {
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    long long t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}


long long mpow2(long long x, long long y, long long mod) {
    long long ret = 1;
    while (y) {
        if (y&1) 
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}


int isPrime(long long p) { // implements by miller-babin
    if (p == 2)             return 1;
    if (p < 2 || !(p&1))    return 0;
    long long q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))  q >>= 1, k++;
    for (int it = 0; it < 2; it++) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++) {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    return 1;
}


int p(int n){
    if(!(n&1)) return 2;
    if(isPrime(n)) return n;

    long long d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, rand() % n + 2);
    
    return d;
}
vector<int> primes;

int dp[100][100];

int f(int a, int b){
    
    int &ans = dp[a][b];
    if(~ans) return ans;

    if(a == 0 || b == 0) return ans = 0;

    if(a == 1) return ans = (b == 2);
    if(b == 1) return ans = (a == 2);

    return ans = f(a-2, b-1) || f(a-1, b-2);
}

map<pair<int, int>, int> hack;

bool solve(int a, int b){
    if(a > b) swap(a, b);

    for(int i = 0; i < primes.size() && a > 1; i++) if(a % primes[i] == 0){
        int q = 0, w = 0;
        while(a % primes[i] == 0) a /= primes[i], q++;
        while(b % primes[i] == 0) b /= primes[i], w++;
        if(!f(q, w)) return 0;
    }

    if(a != 1){
        int ff = p(a);
        int q = 0, w = 0;
        while(a % ff == 0) a /= ff, q++;
        while(b % ff == 0) b /= ff, w++;
        if(!f(q, w)) return 0;
        if(a > 1){
            if(b % a) return 0; b /= a;
            if(b % a) return 0; b /= a;
        }
    }
    if(b > 1) return 0;
    return 1;
}


int main(){
    
    for(int i = 2; i < N; i++) if(!lp[i])
        for(int j = i; j < N; j += i) if(!lp[j])
            lp[j] = i;

    for(int i = 2; i < N; i++) if(i == lp[i])
        primes.push_back(i);

    int q;

    scanf("%d", &q);

    int a, b;

    memset(dp, -1, sizeof dp);

    while(q--){
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        hack[ mp(a, b) ] = solve(a, b);
        printf("%s\n", hack[ mp(a, b) ] ? "Yes" : "No");
    }

    return 0;
}

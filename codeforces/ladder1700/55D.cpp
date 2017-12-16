#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int vet[100], n;
ll dp[22][2][2][3][4][2][7][8][9][1<<6];
int mark[22][2][2][3][4][2][7][8][9][1<<6];
int pass;

inline int s(int bit, int d){
    if(d <= 1) return bit;
    int tw = bit & 3;
    int th = (bit >> 2) & 3;
    int f  = (bit >> 4) & 1;
    int se = (bit >> 5) & 1;
    if(d == 8) tw = 3;
    else if(d == 4) tw = max(tw, 2);
    else if(d == 2 || d == 6) tw = max(tw, 1);
    
    if(d == 9) th = 2;
    else if(d == 3 || d == 6) th = max(th, 1);

    if(d == 5) f = 1;

    if(d == 7) se = 1;

    return (se << 5) | (f << 4) | (th << 2) | tw;
}

inline bool isset(int bit, int d){
    int tw = bit & 3;
    int th = (bit >> 2) & 3;
    int f  = (bit >> 4) & 1;
    int se = (bit >> 5) & 1;
    if(d == 2) return tw >= 1;
    if(d == 3) return th >= 1;
    if(d == 4) return tw >= 2;
    if(d == 5) return f;
    if(d == 6) return tw >= 1 && th >= 1;
    if(d == 7) return se >= 1;
    if(d == 8) return tw == 3;
    if(d == 9) return th >= 2;
}

ll f(int i, int less, int m2, int m3, int m4, int m5, int m7, int m8, int m9, int bit){
    if(i == n){
        if(isset(bit, 2) && m2) return 0;
        if(isset(bit, 3) && m3) return 0;
        if(isset(bit, 4) && m4) return 0;
        if(isset(bit, 5) && !m5) return 0;
        if(isset(bit, 6) && (m2 || m3)) return 0;
        if(isset(bit, 7) && m7) return 0;
        if(isset(bit, 8) && m8) return 0;
        if(isset(bit, 9) && m9) return 0;
        
        return 1;
    }
    
    ll &ans = dp[i][less][m2][m3][m4][m5][m7][m8][m9][bit];
    if(mark[i][less][m2][m3][m4][m5][m7][m8][m9][bit] == pass)
        return ans;
    mark[i][less][m2][m3][m4][m5][m7][m8][m9][bit] = pass;

    ans = 0;
    if(less){
        for(int d = 0; d < 10; d++){
            int nbit = s(bit, d);
            ans += f(i+1, 1, (m2*10 + d) % 2, (m3*10 + d) % 3,
            (m4*10+d) % 4, d == 0 || d == 5, (m7*10+d)%7, (m8*10+d)%8, (m9*10+d)%9, nbit);
        }
    }
    else{
        for(int d = 0; d < vet[i]; d++){
            int nbit = s(bit, d);
            ans += f(i+1, 1, (m2*10 + d) % 2, (m3*10 + d) % 3,
            (m4*10+d) % 4, d == 0 || d == 5, (m7*10+d)%7, (m8*10+d)%8, (m9*10+d)%9, nbit);
        }
        int d = vet[i];
        int nbit = s(bit, d);
        ans += f(i+1, 0, (m2*10 + d) % 2, (m3*10 + d) % 3,
            (m4*10+d) % 4, d == 0 || d == 5, (m7*10+d)%7, (m8*10+d)%8, (m9*10+d)%9, nbit);
    }

    return ans;
}

ll solve(ll x){
    n = 0;
    while(x) vet[n++] = x % 10, x /= 10;
    for(int i = 0; i < n/2; i++)
        swap(vet[i], vet[n-1-i]);
    pass++;
    return f(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

ll solve(ll a, ll b){
    return solve(b) - solve(a-1);
}

int main(){

    int t;

    scanf("%d", &t);

    ll a, b;
    while(t--){
        scanf("%lld %lld", &a, &b);

        printf("%lld\n", solve(a, b));
    }

    return 0;
}

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

const int N = 1000006;

int n;

char s[N];

void back(long long ans){
    if(ans){
        back(ans / 26);
        printf("%c", 'A' + (ans % 26));
    }
}

long long conv(const string & s){
    long long ans = 0;
    long long b = 1;
    for(int i = s.size()-1; i >= 0; i--){
        ans += b * (s[i] - 'A');
        b *= 26;
    }
    return ans;
}

long long f(long long b, long long e){
    long long ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

inline long long sub(long long a, long long b){
    if(a - b < 0) return a - b + MOD;
    return a - b;
}

inline long long add(long long a, long long b){
    if(a + b >= MOD) return a + b - MOD;
    return a + b;
}

inline long long mult(long long a, long long b){
    return (a*b) % MOD;
}

long long hs[N];
long long W[N];

int main(){

    scanf("%s", s);

    n = strlen(s);
    //reverse(s, s+n);

    W[0] = 1;
    long long sum = 0;
    hs[0] = sum = s[n-1]-'A';
    W[1] = 26;
    long long w = f(26, MOD-2);
    for(int i = 1; i < n; i++){
        hs[i] = add(hs[i-1], mult(s[n-1-i]-'A', W[i]));
        sum = add(sum, hs[i]);
        W[i+1] = mult(26, W[i]);
    }

    long long ans = 0;

    ans = sum;

    sum = sub(sum, hs[0]);

    long long tmp;
    long long val = w;
    for(int i = 1; i < n; i++){
        tmp = sub(sum, mult(n-i, hs[i-1]));

        ans = add(ans, mult(tmp, val));
        val = mult(val, w);
        sum = sub(sum, hs[i]);
    }
    if(ans == 0) printf("A");
    back(ans);
    printf("\n");
}

#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)
#define oo (1000000000000000000)

using namespace std;

long long fat[200005];

long long di(long long a, long long e){
    long long b = 1;
    long long ex = MOD - 2;
    while(ex){
        if(ex%2)
            b = (e * b) % MOD;
        ex /= 2;
        e = (e * e) % MOD;
    }
    // printf("a %lld\n",b );
    return (a * b) % MOD;
}

long long C(long long a,long long b){
    // printf("b %lld %lld\n",fat[a],fat[b] );
    if(a == b) return 1;
    return di(fat[a],(fat[b] * fat[a-b]) % MOD);
}

int a[200005],b[200005];

int main(){
    char s[200005];
    fat[0] = 1;
    for(int i = 1; i < 200001; i++)
        fat[i] = (fat[i-1] * i) % MOD;
    scanf("%s",s);
    int n = strlen(s);
    if(s[0] == '(') a[0]++;
    for(int i = 1; i < n; i++){
        a[i] = a[i-1];
        if(s[i] == '(')
            a[i]++;
    }
    for(int i = n-1; i >= 0; i--){
        b[i] = b[i+1];
        if(s[i] == ')')
            b[i]++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            ans += C(a[i] + b[i] - 1,a[i]);
            // printf("%lld %d %d %lld %lld\n",ans,a[i],b[i],fat[a[i]],fat[b[i]] );
        }
        ans %= MOD;
    }
    printf("%lld\n",ans);
    return 0;
}

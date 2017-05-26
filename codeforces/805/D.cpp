#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

#define MOD (1000000007)

using namespace std;

long long f(long long b, long long e){
    long long ans = 1;

    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }

    return ans;
}

char s[1000006];

int main(){

    scanf("%s", s);
    
    int cnt = 0;
    long long ans = 0;

    for(int i = 0; s[i]; i++){
        if(s[i] == 'b') ans = (ans + f(2, cnt)-1 + MOD) % MOD;
        if(s[i] == 'a') cnt++;
    }

    printf("%lld\n", ans);

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int volta[100];

int n, v[102];

int fat[60];

int dp[1 << 17][102];

int f(int bit, int i){
    if(i == n) return 0;
    if(~dp[bit][i]) return dp[bit][i];

    //testa com 1
    int ans = v[i] - 1 + f(bit, i+1);

    for(int val = 2; val < 59; val++){
        if(bit & fat[val]) continue;
        ans = min(ans, abs(v[i] - val) + f(bit | fat[val], i+1));
    }
    return dp[bit][i] = ans;
}

int fatora(int x){
    int ans = 0;
    for(int i = 2; i <= x; i++){
        if(x % i == 0){
            ans |= 1 << volta[i];
            while(x % i == 0) x /= i;
        }
    }
    return ans;
}

int main(){

    volta[3] = 1;
    volta[5] = 2;
    volta[7] = 3;
    volta[11] = 4;
    volta[13] = 5;
    volta[17] = 6;
    volta[19] = 7;
    volta[23] = 8;
    volta[29] = 9;
    volta[31] = 10;
    volta[37] = 11;
    volta[41] = 12;
    volta[43] = 13;
    volta[47] = 14;
    volta[53] = 15;

    for(int i = 2; i < 59; i++) fat[i] = fatora(i);

    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", v+i);

    memset(dp, -1, sizeof dp);

    int bit = 0;

    for(int i = 0; i < n; i++){
        if(f(bit, i) == v[i]-1 + f(bit, i+1)){
            printf("1 ");
            continue;
        }
        for(int val = 2; val < 59; val++){
            if(bit & fat[val]) continue;
            if(f(bit, i) == abs(v[i] - val) + f(bit | fat[val], i+1)){
                printf("%d ", val);
                bit = bit | fat[val];
                break;
            }
        }
    }
    printf("\n");

    return 0;
}

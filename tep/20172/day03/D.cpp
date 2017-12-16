#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

char s[1000006];

int back(char c){
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if(c >= 'a' && c <= 'z') return c - 'a' + 36;
    return 0;
}

int main(){

    ll x;

    while(scanf(" %s", s) == 1){
        int d = 0;
        int start = 2;
        for(int i = 0; s[i]; i++){
            d += back(s[i]);
            start = max(start, back(s[i])+1);
        }

        int ans = -1;
        for(int i = start; i <= 62; i++){
            if(d % (i-1) == 0){
                ans = i;
                break;
            }
        }
        if(ans == -1) printf("such number is impossible!\n");
        else printf("%d\n", ans);
    }


    return 0;
}

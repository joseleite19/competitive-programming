#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 1000006;

char s[N], t[N];

bool is_p(ll x){
    for(ll i = 2; i*i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}

int f(char c){
    if(c >= 'a' && c <= 'z') return c - 'a' + 1;
    return c - 'A' + 27;
}

int main(){
    ll x;
    while(scanf(" %s", s) == 1){
        x = 0;
        for(int i = 0; s[i]; i++)
            x += f(s[i]);
        printf("%s\n", is_p(x) ? "It is a prime word." : "It is not a prime word.");
    }


    return 0;
}

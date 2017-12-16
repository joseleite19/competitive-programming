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

bool is_legal(int base, char c){
    int val;
    if(c >= '0' && c <= '9') val = c - '0';
    else val = c - 'A'+10;
    return val >= 0 && val < base;
}

int f(char c){
    if(c >= '0' && c <= '9') return c - '0';
    return c - 'A'+10;
}

ll getnum(int i, int b){
    if(i == 0) return f(s[i]);
    return getnum(i-1, b)*b + f(s[i]);
}

char back(int x){
    if(x < 10) return x + '0';
    return x - 10 + 'A';
}

void print(ll x, int b){
    if(x){
        print(x / b, b);
        printf("%c", back(x % b));
    }
}

int main(){
    int a, b;
    while(scanf(" %d %d %s", &a, &b, s) == 3){
        bool illegal = false;
        for(int i = 0; s[i]; i++){
            if(!is_legal(a, s[i]))
                illegal = true;
        }

        if(illegal){
            printf("%s is an illegal base %d number\n", s, a);
            continue;
        }

        ll x = getnum(strlen(s)-1, a);
        printf("%s base %d = ", s, a);
        if(!x) printf("0");
        else print(x, b);
        printf(" base %d\n", b);
    }

    return 0;
}

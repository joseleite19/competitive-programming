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

int main(){

    char c;

    while(scanf(" %s %c %s", s, &c, t) == 3){
        printf("%s %c %s\n", s, c, t);

        bool zero = 0;
        bool can = true;
        long long a = 1, b = 1;
        if(strlen(s) > 10) can = false, printf("first number too big\n");
        else{ 
            sscanf(s, "%lld", &a);
            if(a >= (1LL << 31)) can = false, printf("first number too big\n");
            if(a == 0) zero = 1;
        }

        if(strlen(t) > 10) can = false, printf("second number too big\n");
        else{

            sscanf(t, "%lld", &b);
            if(b >= (1LL << 31)) can = false, printf("second number too big\n");
            if(b == 0) zero = 1;
        }
        if(c == '*' && zero) can = 1;

        if(can){
            if(c == '+'){
                if(a + b >= (1LL << 31)) can = false;
            }
            if(c == '*'){
                if(a * b >= (1LL << 31)) can = false;
            }
        }
        if(!can) printf("result too big\n");
    }


    return 0;
}

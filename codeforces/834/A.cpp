#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

int f(char c){
    if(c == 94) return 0;
    if(c == 62) return 1;
    if(c ==118) return 2;
    if(c == 60) return 3;
    assert(0);
}

int main(){
    char s, e;
    int n;

    scanf(" %c %c %d", &s, &e, &n);

    n %= 4;

    if(abs(f(s) - f(e)) == 2 || s == e) return printf("undefined\n"), 0;

    printf("%s\n", (f(s) + n) % 4 == f(e) ? "cw" : "ccw");

    return 0;
}

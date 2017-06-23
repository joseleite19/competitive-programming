#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d, e, f;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int k1 = (c - a) / e;
    int k2 = (d - b) / f;

    if((c - a) % e) return printf("NO\n"), 0;
    if((d - b) % f) return printf("NO\n"), 0;
    if((k1 - k2) & 1) return printf("NO\n"), 0;
    printf("YES\n");


    return 0;
}

#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int c, v0, v1, a, l;

int main(){

    scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);

    int atual = v0;

    if(v0 >= c) return printf("1\n"), 0;

    int inc = v0;
    int day = 1;
    while(1){
        inc += a;
        inc = min(inc, v1);
        atual += inc - l;
        day++;
        if(atual >= c) break;
    }
    printf("%d\n", day);


    return 0;
}

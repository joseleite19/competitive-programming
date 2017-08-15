#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int v[N], l, x, y, n;

int main(){

    scanf("%d %d %d %d", &n, &l, &x, &y);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    set<int> s;

    int has = 0;
    for(int i = 0; i < n; i++){
        if(s.count(v[i] - x)) has |= 1;
        if(s.count(v[i] - y)) has |= 2;
        s.insert(v[i]);
    }

    if(has == 3) return printf("0\n"), 0;
    if(has == 1) return printf("1\n%d\n", y), 0;
    if(has == 2) return printf("1\n%d\n", x), 0;

    map<int, int> cnt;

    for(int i = 0; i < n; i++){
        if(x + v[i] <= l) cnt[ x + v[i] ] |= 1;
        if(v[i] - x >= 0) cnt[ v[i] - x ] |= 1;
        if(y + v[i] <= l) cnt[ y + v[i] ] |= 2;
        if(v[i] - y >= 0) cnt[ v[i] - y ] |= 2;
    }

    for(pair<int, int> x : cnt) if(x.second == 3)
        return printf("1\n%d\n", x.first), 0;


    printf("2\n%d %d\n", x, y);

    return 0;
}

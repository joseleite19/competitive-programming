#include <bits/stdc++.h>

using namespace std;

const int N = 10004;

int n, m, p[N];


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", p+i), p[i]--;

    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c); a--; c--; b;
        int t = a;
        for(int i = a; i < b; i++)
            if(p[i] < p[c])
                t++;
        printf("%s\n", t == c ? "Yes" : "No");
    }


    return 0;
}

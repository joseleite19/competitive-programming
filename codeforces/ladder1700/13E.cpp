#include <bits/stdc++.h>

using namespace std;

const int N = 100005, B = 317;

int n, m, v[N];

int nx[N], ans[N];

void comp(int x, int y){
    for(int i = y; i >= x; i--){
        if(i + v[i] > y){
            nx[i] = i;
            ans[i] = 1;
        }
        else{
            nx[i] = nx[ i+v[i] ];
            ans[i] = ans[ i+v[i] ]+1;
        }
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    for(int l = 0; ; l++){
        int x = l * B;
        int y = min(n-1, (l+1)*B-1);
        comp(x, y);
        if(y == n-1) break;
    }

        int t, a, b, l, x, y;
    while(m--){
        scanf("%d", &t);
        if(t == 0){
            scanf("%d %d", &a, &b); a--;
            l = (a / B);
            x = l * B;
            y = min(n-1, (l+1)*B-1);
            v[a] = b;
            comp(x, y);
        }
        else{
            scanf("%d", &a); a--;
            int p = 0;
            while(a < n){
                p += ans[a];
                a = nx[a];

                if(a + v[a] >= n) break;
                a += v[a];
            }
            printf("%d %d\n", a+1, p);
        }
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void file(){
    freopen("h.in", "r", stdin);
}

int main(){
    file();
    int m, n;

    scanf("%d %d", &m, &n);

    int ans = 0;
    for(int x = 0; x <= m; x++){
        for(int y = x; y <= m; y++){
            for(int z = y; z <= m; z++){
                if(x*x + y*y == z*z)
                    ans++;
            }
        }
    }
    ans += (n-2)*(m+1);

    printf("%d\n", ans);


    return 0;
}

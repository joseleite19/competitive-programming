#include <bits/stdc++.h>

using namespace std;



int main(){
    int n, r;

    for(int tc = 1; scanf("%d %d", &r, &n) == 2 && n+r; tc++){
        printf("Case %d: ", tc);
        if(r > 27*n) printf("impossible\n");
        else printf("%d\n", max((r+n-1)/n -1, 0));
    }



    return 0;
}

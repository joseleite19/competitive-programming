#include <bits/stdc++.h>

using namespace std;

void file(){
    freopen("d.in", "r", stdin);
}

int main(){
    file();
    int x, y;
    int inv_x, inv_y;

    scanf("%d %d", &x, &y);
    inv_x = y;
    inv_y = x;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a == 1) {
            printf("YES\n");
        } else if (!((x-1)%a) && !((y-1)%a)) {
            printf("YES\n");
        } else if (!((x-1)%a) && !((y)%a) && a == 2) {
            printf("YES\n");
        } else if (!((x-2)%a) && !((y-1)%a) && a == 2) {
            printf("YES\n");
        } else if (!((x-2)%a) && !((y)%a)) {
            printf("YES\n");
        } else if (!((inv_x-1)%a) && !((inv_y-1)%a)) {
            printf("YES\n");
        } else if (!((inv_x-1)%a) && !((inv_y)%a) && a == 2) {
            printf("YES\n");
        } else if (!((inv_x-2)%a) && !((inv_y-1)%a) && a == 2) {
            printf("YES\n");
        } else if (!((inv_x-2)%a) && !((inv_y)%a)) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
    }


    return 0;
}

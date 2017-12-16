#include <bits/stdc++.h>

using namespace std;

int main(){
    int v[3], q[3];

    for(int i = 0; i < 3; i++) scanf("%d", v+i);
    for(int i = 0; i < 3; i++) scanf("%d", q+i);

    sort(q, q+3); sort(v, v+3);

    for(int i = 0; i < 3; i++) if(q[i] != v[i])
        return printf("NO\n"), 0;

    if(v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) printf("YES\n");
    else printf("NO\n");

    return 0;
}

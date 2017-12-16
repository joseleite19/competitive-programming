#include <bits/stdc++.h>

char s[2000];

int cnt[256];

int main(){
    int n, k;

    scanf("%d %d %s", &n, &k, s);

    for(int i = 0; i < n; i++)
        cnt[ s[i] ]++;

    for(int i = 0; i < 256; i++)
        if(cnt[i] > k)
            return printf("NO\n"), 0;

    printf("YES\n");

    return 0;
}

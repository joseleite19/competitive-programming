#include <bits/stdc++.h>

using namespace std;

int n, k;

char s[222][222];

int f(int q){
    for(int i = 0; i < k; i++){
        int j = 0;
        while(i+j < k && s[q-1][i+j] == s[q][j]) j++;
        if(j == k - i) return j;
    }
    return 0;
}


int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &k, &n);

        for(int i = 0; i < n; i++)
            scanf(" %s", s[i]);

        int ans = n*k;

        for(int i = 1; i < n; i++)
            ans -= f(i);

        printf("%d\n", ans);
    }


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

char s[33];
int cnt[1000];

int n;
int f(int i, int ja){
    if(i == n) return 1;

    if(ja) s[i] = 9;
    while(s[i] >= (i ? 0 : 1)){
        if(cnt[ s[i] ] == 2){ s[i]--; ja = 1; continue;}
        cnt[ s[i] ]++;
        if(f(i+1, ja))
            return 1;
        cnt[ s[i] ]--;
        s[i]--;
        ja = 1;
    }
    s[i] = 9;
    return 0;
}

int main(){

    scanf("%s", s);
    n = strlen(s);

    for(int i = 0; i < n; i++)
        s[i] -= '0';

    if(!f(0, 0)){
        n--;
        for(int i = 0; i < 10; i++) cnt[i] = 0;
        for(int i = 0; i < n; i++){
            for(int d = 9; d >= 0; d--){
                if(cnt[d] < 2){
                    cnt[d]++;
                    printf("%d", d);
                    break;
                }
            }
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < n; i++)
            printf("%d", s[i]);
        printf("\n");
    }

    return 0;
}

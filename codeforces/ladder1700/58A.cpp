#include <bits/stdc++.h>

char s[200], *t = "hello";

int main(){

    scanf("%s", s);

    int j = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == t[j]) j++;
        if(j == 5) break;
    }
    printf("%s\n", j == 5 ? "YES" : "NO");




}

#include <bits/stdc++.h>

using namespace std;

int v[256];
char s[100];


int main(){

    scanf("%s", s);
    int n = strlen(s);

    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 'a'; j < s[i]; j++)
            tmp = max(tmp, v[j]);
        v[ s[i] ] = tmp+1;
        ans = max(ans, v[s[i]]);
    }

    printf("%d\n", 26 - ans);



}

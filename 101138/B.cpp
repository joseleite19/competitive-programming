#include <bits/stdc++.h>

using namespace std;

char s[222];

int main(){

    int t;

    scanf("%d", &t);

    while(t--){
        scanf(" %s", s);

        int n = strlen(s);
        bool can = true;

        if(n & (n-1)) can = false;

        for(int i = 0; i < n; i += 2){
            if(s[i] == 'A' && s[i+1] == 'A')
                can = false;
        }


        printf("%s\n", can ? "YES" : "NO");
    }


    return 0;
}

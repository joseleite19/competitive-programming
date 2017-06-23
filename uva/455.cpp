#include <bits/stdc++.h>

using namespace std;

char s[222];

int main(){

    int t;
    
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        if(tc > 1) printf("\n");
        scanf("%s", s);
        string a = s;
        string b = s;

        b = b.substr(1) + b;
        printf("%d\n", 1+b.find(a));
    }


    return 0;
}

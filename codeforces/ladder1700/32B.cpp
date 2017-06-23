#include <bits/stdc++.h>

using namespace std;

char s[1000];

int main(){

    scanf("%s", s);

    int n = strlen(s);

    for(int i = 0; i < n; ){
        if(s[i] == '.') printf("0"), i++;
        else if(s[i+1] == '.') printf("1"), i += 2;
        else printf("2"), i += 2;
    }

    printf("\n");




    return 0;
}

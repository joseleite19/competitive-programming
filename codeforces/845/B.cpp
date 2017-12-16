#include <bits/stdc++.h>

using namespace std;

char s[100];

int main(){

    scanf("%s", s);

    for(int i = 0; i < 6; i++) s[i] -= '0';

    int a = 0, b = 0;

    for(int i = 0; i < 3; i++) a += s[i];
    for(int i = 3; i < 6; i++) b += s[i];

    sort(s, s+3);
    sort(s+3, s+6);

    int ans = 0;

    if(a == b) return printf("0\n"), 0;

    if(a < b){
        for(int i = 0; i < 3; i++)
            swap(s[i], s[i+3]);
        swap(a, b);
    }

    a -= b;
    for(int i = 0; i < 3; i++)
        if(s[i] >= a)
            return printf("1\n"), 0;

    for(int i = 3; i < 6; i++)
        if(9 - s[i] >= a)
            return printf("1\n"), 0;

    if(s[1] + s[2] >= a) return printf("2\n"), 0;
    if((9 - s[3]) + (9- s[4]) >= a) return printf("2\n"), 0;
    printf("3\n");
    
}

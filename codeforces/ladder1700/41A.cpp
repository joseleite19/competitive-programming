#include <bits/stdc++.h>

using namespace std;

char s[10000], t[10000];

int main(){

    scanf("%s %s", s, t);
    string ss = s;
    string sss = t;
    
    reverse(sss.begin(), sss.end());

    printf("%s\n", ss == sss ? "YES" : "NO");

}

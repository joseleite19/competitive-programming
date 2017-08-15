#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

char s[N], t[N];

int main(){

    for(int tc = 1; scanf("%s %s", s, t) == 2; tc++){
        if(tc > 1) printf("\n");
        string a = s, b = t;

        printf("Instancia %d\n%s\n", tc, b.find(a) != string::npos ? "verdadeira" : "falsa");
    }


    return 0;
}

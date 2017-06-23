#include <bits/stdc++.h>

using namespace std;

const int N = 3003;

char a[N], b[N], s[N];

int main(){
    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        if(tc > 1) printf("\n");
        scanf(" %[^\n] %[^\n]", a, b);
        getchar();
        printf("%s\n%s\n", b, a);

        map<char, char> f;
        for(int i = 0; i < 256; i++) f[i] = i;
        assert(strlen(a) == strlen(b));
        for(int i = 0; a[i]; i++) f[ a[i] ] = b[i];

        while(scanf("%[^\n]", s) == 1){
            getchar();
            for(int i = 0; s[i]; i++) printf("%c", f[ s[i] ]);
            printf("\n");
        }
    }


    return 0;
}

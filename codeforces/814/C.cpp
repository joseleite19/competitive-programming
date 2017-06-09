#include <bits/stdc++.h>

using namespace std;

int n;
char s[1505];

int vet[26][1505];




int main(){

    scanf("%d %s", &n, s);

    for(int c = 0; c < 26; c++){
        vet[c][0] = 0;
        for(int i = 1; i <= n; i++)
            vet[c][i] = n;
    }

    for(int c = 0; c < 26; c++){
        for(int i = 0; i < n; i++){
        int t = 0;
            for(int j = i; j < n; j++){
                if(s[j] != 'a'+c) t++;

                vet[c][ j - i + 1 ] = min(vet[c][j-i+1], t);
            }
        }
    }

    int q;

    scanf("%d", &q);

    while(q--){
        int x; char c;
        scanf("%d %c", &x, &c);
        c -= 'a';

        int id = upper_bound(vet[c], vet[c]+n+1, x) - vet[c];
        id--;
        printf("%d\n", id); 
    }







    return 0;
}

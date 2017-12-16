#include <bits/stdc++.h>

using namespace std;

#define oo 1000000000

int chartoid(char c){
    return c < 'a' ? 26 + c - '0' : c - 'a';
}

int main(){
    int nomes[103][36], i, n, m, k, aux[36], max, j, minatual, id;
    char nick[100][30], gang[100][30], s[55];

    scanf("%d", &k);
    
    memset(nomes, 0, sizeof(nomes));
    
    for(i = 0; i < k; i++){
        scanf("%s %s", nick[i], gang[i]);
        for(n = 0; nick[i][n]; n++)
            nomes[i][ chartoid(nick[i][n]) ]++;
        for(n = 0; gang[i][n]; n++)
            nomes[i][ chartoid(gang[i][n]) ]++;
    }
    max = id = -1;
    for(int K = 0; K < k; K++){
        scanf("%d %d", &n, &m);

        memset(aux, 0, sizeof(aux));
        for(i = 0; i < n; i++){
            scanf("%s", s);
            for(j = 0; s[j]; j++)
                aux[chartoid(s[j])]++;
        }

        minatual = oo;
        for(j = 0; j < 26; j++)
            if(nomes[K][j])
                minatual = min(minatual, aux[j]/nomes[K][j]);

        if(minatual > max){
            max = minatual;
            id = K;
        }
    }
    printf("%s %s\n", nick[id], gang[id]);

    return 0;
}
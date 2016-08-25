#include <bits/stdc++.h>

using namespace std;

int main(){
    int nomes[103][26], i, n, m, k, aux[26], max, j, minatual, id;
    char s1[100][30], s2[100][30], s[55], c;

    scanf("%d", &k);
    memset(nomes, 0, sizeof(nomes));
    for(i = 0; i < k; i++){
        scanf("%s %s", s1[i], s2[i]);
        for(n = 0; s1[i][n]; n++)
            nomes[i][s1[i][n] - 'a']++;
        for(n = 0; s2[i][n]; n++)
            nomes[i][s2[i][n] - 'a']++;
    }
    max = id = -1;
    for(int K = 0; K < k; K++){
        scanf("%d %d", &n, &m);
        memset(aux, 0, sizeof(aux));
        for(i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf(" %c", &c);
                aux[c - 'a']++;
            }
        }
        minatual = 100000000;
        for(j = 0; j < 26; j++){
            if(nomes[K][j])
                minatual = min(minatual, aux[j]/nomes[K][j]);
            printf("(%d %d) ", aux[j], nomes[K][j]);
        }
        printf("\n");
        printf("\n");

        if(minatual > max){
            max = minatual;
            id = K;
        }
    }
    printf("%s %s\n", s1[id], s2[id]);

    return 0;
}
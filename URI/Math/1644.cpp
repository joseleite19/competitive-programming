#include <cstdio>

int main(){
    int n, m, p[100], v[100], final[100];
    char text[100];

    while(scanf("%d %d", &n, &m) == 2 && n){

        for(int i = 1; i <= n; i++){
            scanf("%d%*c", p+i);
            v[ p[i] ] = i;
        }

        for(int i = 1; i <= n; i++){
            int aux = v[i], cicleLength;
            for(cicleLength = 1; aux != i; cicleLength++)
                aux = v[aux];

            int rem = m % cicleLength;
            final[i] = i;
            for(int j = 0; j < rem; j++)
                final[i] = v[final[i]];
        }

        scanf("%[^\n]%*c", text);

        for(int i = 1; i <= n; i++)
            printf("%c", text[ final[i]-1 ]);
        printf("\n");
    }

    return 0;
}
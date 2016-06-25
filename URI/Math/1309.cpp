#include <cstdio>
#include <cstring>

int main(){
    char a[13];
    int i, d, tamanho;

    while(scanf(" %s",&a) == 1){
        scanf(" %d", &d);
        tamanho = strlen(a);
        printf("$%c", a[0]);
        for(i = 1; i < tamanho; i++){
            if((tamanho-i) % 3 == 0) printf(",");
            printf("%c", a[i]);
        }
        printf(".%.2d\n", d);
    }

    return 0;
}
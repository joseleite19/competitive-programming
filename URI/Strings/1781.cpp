#include <stdio.h>
#include <string.h>
#include <cassert>
 
int main(){
    int t, T, q, a, b, inic, iniv, tamc, tamv, tam, i, letra[10007], c, v;
    char s[10007], consoante[10007], vogais[10007];
   
   
    scanf("%d%*c", &T);
   
    for(t = 1; t <= T; t++){
        tamc = tamv = iniv = inic = 0;
        scanf("%s%*c", s);
   
        for(i = 0; s[i]; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vogais[tamv++] = s[i];
                letra[i] = 1;
            }
            else{
                consoante[tamc++] = s[i];
                letra[i] = 0;
            }
        }
        tam = i;
		assert(iniv < 10007);
        assert(tamv < 10007);
		assert(tamc < 10007);

   
        printf("Caso #%d:\n", t);
        scanf("%d%*c", &q);
        
        c = v = 0;
        while(q--){
            scanf("%d%*c", &a);
            if(a == 0){
                scanf("%d%*c", &b);
                v = (v + b + tamv) % tamv;
            }
            else if(a == 1){
                scanf("%d%*c", &b);
                c = (c + b + tamc) % tamc;
            }
            else if(a == 2){
                inic = (inic - c + tamc) % tamc;
                iniv = (iniv - v + tamv) % tamv;
                // if(inic < 0) inic = (inic + ((-inic) / tamc + 1)*tamc) % tamc;
                // if(iniv < 0) iniv = (iniv + ((-iniv) / tamv + 1)*tamv) % tamv;
                // assert(tamv < 10007);
                assert(inic);
                // assert(iniv < 10007);
                // assert(tamc < 10007);

                for(i = 0, c = inic, v = iniv; i < tam; i++){
                    if(letra[i]){
                //         // printf("%c", vogais[v]);
                //         // printf("%d %d\n", v, tamv);
                //         v = (v+1)%tamv;
                    }
                    else{
                    	// printf("%d\n", c);
                //         // else printf("%c", consoante[c]);
                //         // printf("%d %d\n", c, tamc);
                //         c = (c+1)%tamc;
                    }
                }
                printf("\n");
            }
        }
    }
   
    return 0;
}
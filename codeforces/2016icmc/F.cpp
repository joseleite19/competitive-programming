#include <bits/stdc++.h>
 
using namespace std;
 
struct coisa{
    char tipo;
    int a,b,c,t;
    coisa(){}
    coisa(char d, int e, int f, int g, int h){
        tipo = d; a = e; b = f; t = h; c = g;
    }
};
 
int n, ans[100005];
vector<coisa> v, outro;
 
int  main(){
    int n, m, q, i, a,b,d;
    char c;
   
    scanf("%d %d %d", &n, &m, &q);
    memset(ans,-1,sizeof ans);
    int ind = 0;
   
    for(i = 0; i < q; i++){
        scanf(" %c", &c);
       
        if(c == 'C'){
            scanf("%d %d", &a, &b);
            v.push_back(coisa('C',a,b,ind,i);
            ans[ind++] = -1;
        }
        else{
            scanf("%d %d %d", &a, &b, &d);
//          printf("%c %d %d %d %d\n", c, a, b, d, c == 'H');
            if(c == 'H') v.push_back(coisa('H',a,b,d,i));
            else v.push_back(coisa('V',a,b,d));
        }
    }
 
    for(i = q-1; i >= 0; i--){
        if(v[i].tipo == 'C'){
            h[v[i].a] = v[i];
            h[v[i].b] = v[i];
        }
    }
 
    return 0;
}
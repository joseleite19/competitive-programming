#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

#define oo 1000000000000000007

using namespace std;

const int N = 3000;

int n;
char s[10];
int a[444], b[444], t[444];

int v[22];

int cnt = 0, q, j;

void tov(int bit){
    for(j = 0; j < 20; j++){
        if(bit & (1 << j)) v[j] = 1;
        else v[j] = 0;
    }

}
int zero, tam, tmp;
int perform(int bit){
    for(j = 0; j < n; j++){
        if(t[j] == 1){
            //sort(v+a[i], v+b[i]);
            tam = b[j] - a[j];
            tmp = ((1 << tam)-1) << a[j];
            cnt = __builtin_popcount(tmp & bit);
            zero = tam - cnt;
            bit &= ~tmp;
            bit |= ((1 << cnt)-1) << (zero + a[j]);
            /*for(q = a[j]; q < b[j]; q++)
                cnt += v[q];
            for(q = b[j]-1; q >= a[j]; q--){
                v[q] = (cnt > 0);
                cnt--;
            }*/
        }
        else{
            if(bit & (1 << a[j])){
                if(bit & (1 << b[j])) continue;
                else{
                    bit &= ~(1 << a[j]);
                    bit |= (1 << b[j]);
                }
            }
           //if(v[ a[j] ] > v[ b[j] ]) swap(v[ a[j] ], v[ b[j] ]); 
        }
    }
    return bit;
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %s %d %d", s, a+i, b+i);
        if(s[0] == 's') t[i] = 1;
        else t[i] = 2;
    }

    const int limit = (1 << 20)-1;
    bool can;
    int array;
    for(int bit = 1; bit < limit; bit++){
        //tov(bit);
        array = perform(bit);
        can = true;
        for(int i = 0; i < 19; i++){
            if(array & (1 << i)){
                if(array & (1 << (i+1))){}
                else{
                    can = false;
                }
            }
        }
        if(!can){
            printf("incorrect\n"); tov(bit);
            printf("%d", v[0]);
            for(int i = 1; i < 20; i++) printf(" %d", v[i]);
            printf("\n");
            return 0;
        }
    }

    printf("correct\n");


}

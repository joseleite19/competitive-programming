#include <cstdio>
#include <cstring>

int main(){
    int t, n, a, i, k;
    long long int m;
    char key[23];
    scanf(" %d",&t);
    while(t--){
        scanf(" %d%s", &n, key);
        k = strlen(key);
        m = n;
        a = n-k;
        i = 1;
        while(a){
            m *= a;
            i++;
            a = n - i*k;
        }
        printf("%lld\n", m);
    }

    return 0;
}
#include <cstdio>

int main(){
    int n, m, c, p, s;

    while(scanf("%d %d %d", &n, &m, &c), n+m){
        if(c){
            p = (n-6) / 2;
            s = (n-7) / 2;
        }
        else{
            p = (n-7) / 2;
            s = (n-6) / 2;
        }
        m -= 7;
        s *= m/2;
        if(m & 1)
            m += 2;
        p *= m/2;
        printf("%d\n", p+s);
    }
}
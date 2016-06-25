#include <cstdio>

int main(){
    long long int x, y, a;
    int carry, b, p, s, m;

    while(scanf(" %lld %lld", &x, &y) == 2, x, y){
        carry = 0;
        a = x + y;

        while(a){
            p = x % 10;
            s = y % 10;
            if(p > s){
                b = p;
                m = s;
            }
            else{
                b = s;
                m = p;
            }
            if(b > (a%10) || (b == a % 10 && m))
                carry++;
            a /= 10;
            x /= 10;
            y /= 10;
        }
        if(carry == 0) printf("No carry operation.\n");
        else if(carry == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",carry);
    }
}
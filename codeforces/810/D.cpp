#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)

using namespace std;

int n, k;

char s[10], x1, x2;

bool f(int a, int b){
    printf("1 %d %d\n", a, b); fflush(stdout);
    scanf("%s", s);
    return s[0] == 'T';
}

int main(){

    scanf("%d %d", &n, &k);


    int lo = 1, hi = n, x1, x2 = -1;

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(f(mid, mid+1)) hi = mid;
        else lo = mid+1;
    }

    if(f(lo, hi)) x1 = lo;
    else x1 = hi;

    if(x1+1 <= n){ // right
        lo = x1+1, hi = n;
        while(lo + 1 < hi){
            int mid = (lo + hi) / 2;
            if(f(mid, mid+1)) hi = mid;
            else lo = mid+1;
        }
        if(f(lo, hi)){
            if(f(lo, x1)) x2 = lo;
        }
        else if(f(hi, x1)) x2 = hi;
    }

    if(1 <= x1-1 && x2 == -1){
        lo = 1, hi = x1-1;
        while(lo + 1 < hi){
            int mid = (lo + hi) / 2;
            if(f(mid, mid+1)) hi = mid;
            else lo = mid+1;
        }
        if(f(lo, hi)){
            if(f(lo, x1)) x2 = lo;
        }
        else if(f(hi, x1)) x2 = hi;
    }

    printf("2 %d %d\n", x1, x2); fflush(stdout);

	return 0;
}

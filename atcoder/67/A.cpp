#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007
#define oo 1000000000000000000

using namespace std;

int main(){

    int a, b;

    scanf("%d %d", &a, &b);

    if(a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0) printf("Possible\n");
    else printf("Impossible\n");



    return 0;
}

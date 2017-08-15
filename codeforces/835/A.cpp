#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;


int main(){
    int n, a, b, c, d;

    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    int q = n*a + 2*c;
    int w = n*b + 2*d;

    if(q < w) printf("First\n");
    else if(q > w) printf("Second\n");
    else printf("Friendship\n");



    return 0;
}

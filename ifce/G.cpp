#include <bits/stdc++.h>

using namespace std;


int main(){

    int x;

    scanf("%d", &x);

    x %= 3;
    if(x == 0) printf("Tiangua\n");
    if(x == 1) printf("Sobral\n");
    if(x == 2) printf("Ubajara\n");

}

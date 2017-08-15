#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, a, b;

int main(){

    scanf("%d %d %d", &n, &a, &b);

    int ans = 0, c = 0;
    int x;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x == 1){
            if(a) a--;
            else if(b) b--, c++;
            else if(c) c--;
            else ans++;
        }
        else{
            if(b) b--;
            else ans+= 2;
        }
    }
    printf("%d\n", ans);




    return 0;
}

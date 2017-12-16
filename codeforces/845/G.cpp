#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

#define oo 1000000000

using namespace std;

const int N = 200005;

int n;

pair<int, int> v[N];

int main(){

    printf("%f\n", powf(809.0f, 2.0f)*88.0f*3.14159265);

    scanf("%d", &n);

    int t;
    int ans = 0;
    stack<int> ls;
    ls.push(oo);
    int x;
    int over = 0;
    int s;
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d", &s);
            while(s > ls.top()) ans++, ls.pop();
        }
        else if(t == 2){
            if(over) ans += over, over = 0;
        }
        else if(t == 3){
            scanf("%d", &x);
            ls.push(x);
            while(s > ls.top()) ans++, ls.pop();
        }
        else if(t == 4){
            over = 0;
        }
        else if(t == 5){
            ls.push(oo);
        }
        else if(t == 6){
            over++;
        }
    }

    printf("%d\n", ans);
    
}

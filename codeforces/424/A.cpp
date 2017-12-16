#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

char s[N];

int main(){

    int n;

    scanf("%d %s", &n, s);

    int ans = 0;

    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'X'){
            a++;
            if(a > n/2){
                ans++;
                a--;
                b++;
                s[i] = 'x';
            }
        }
        else{
            b++;
            if(b > n/2){
                b--;
                a++;
                ans++;
                s[i] = 'X';
            }
        }
    }

    printf("%d\n%s\n", ans, s);


    return 0;
}

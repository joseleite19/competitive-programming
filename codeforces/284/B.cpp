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
const int N = 200005;

int n;
char s[N];

int main(){

    scanf("%d %s", &n, s);

    int a = 0, f = 0, i = 0;

    for(int q = 0; q < n; q++)
        if(s[q] == 'A') a++;
        else if(s[q] == 'F') f++;
        else if(s[q] == 'I') i++;

    if(i) printf("%d\n", i > 1 ? 0 : i);
    else printf("%d\n", a);


    return 0;
}

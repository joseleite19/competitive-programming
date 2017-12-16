#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 200005;

char s[N];

int main(){

    scanf("%s", s);

    int n = strlen(s);

    for(int i = 0; i < n/2; i++)
        s[n-1-i] = s[i];
    printf("%s\n", s);

    return 0;
}

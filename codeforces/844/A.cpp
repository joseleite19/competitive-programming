#include <bits/stdc++.h>

using namespace std;

char s[10000];

int main(){
    int k;

    scanf("%s %d", s, &k);

    int n = strlen(s);

    if(n < k) return printf("impossible\n"), 0;

    set<char> ss;

    for(int i = 0; i < n; i++)
        ss.insert(s[i]);
    printf("%d\n", max(0, k - int(ss.size())));

    return 0;
}

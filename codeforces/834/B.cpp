#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 1000006;

char s[N];
int cnt[N];

int l[26], r[26];

int main(){
    int n, k;

    scanf("%d %d %s", &n, &k, s);

    for(int i = 0; i < 26; i++) l[i] = n, r[i] = -1;

    for(int i = 0; i < n; i++){
        int c = s[i] - 'A';
        l[c] = min(l[c], i);
        r[c] = max(r[c], i);
    }

    for(int i = 0; i < 26; i++){
        for(int j = l[i]; j <= r[i]; j++)
            cnt[j]++;
    }

    for(int i = 0; i < n; i++) if(cnt[i] > k)
        return printf("YES\n"), 0;

    printf("NO\n");


    return 0;
}

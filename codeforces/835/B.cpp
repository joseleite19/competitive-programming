#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 100005;

char s[N];
int k;

int main(){

    scanf("%d %s", &k, s);
    int n = strlen(s);

    int cnt = 0;

    multiset<int> ss;

    for(int i = 0; i < n; i++)
        cnt += s[i]-'0', ss.insert(s[i]-'0');

    int ans = 0;
    while(cnt < k){
        cnt -= *ss.begin();
        cnt += 9;
        ans++;
        ss.erase(ss.begin());
    }

    printf("%d\n", ans);



    return 0;
}

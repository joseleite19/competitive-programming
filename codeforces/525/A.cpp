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
const int N = 500005;

int cnt[333];

char s[N];

int main(){

    int n;

    scanf("%d %s", &n, s);

    int ans = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(cnt[ s[i] - 'A' ]){
                cnt[ s[i] - 'A' ]--;
            }
            else ans++;
        }
        else cnt[ s[i] - 'a' ]++;
    }

    printf("%d\n", ans);






    return 0;
}

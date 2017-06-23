#include <bits/stdc++.h>

using namespace std;

char s[50];
int n;

int cnt[256];

long long fat[32];

long long f(int x){
    multiset<int> s;
    for(int i = 1; i <= x; i++){
        int j = i;
        for(int k = 2; k <= j; k++){
            while(j % k == 0){
                s.insert(k);
                j /= k;
            }
        }
    }

    for(int i = 'a'; i <= 'z'; i++){
        for(int j = 1; j <= cnt[i]; j++){
            int q = j;
            for(int k = 2; k <= j; k++){
                while(q % k == 0){
                    s.erase(s.find(k));
                    q /= k;
                }
            }
        }
    }
    long long ans = 1;
    for(int x : s) ans *= x;
    return ans;
}

int main(){
    fat[0] = 1;
    for(int i = 1; i < 32; i++)
        fat[i] = i*fat[i-1];

    while(scanf(" %s", s) == 1 && s[0] != '#'){
        n = strlen(s);
        for(int i = 0; i < 256; i++) cnt[i] = 0;
        for(int i = 0; i < n; i++) cnt[ s[i] ]++;

        multiset<char> ss;
        for(int i = 0; i < n; i++) ss.insert(s[i]);

        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(*ss.begin() != s[i]){
                for(int j = 'a'; j <= 'z'; j++){
                    if(j == s[i]) break;
                    if(!cnt[j]) continue;
                    cnt[j]--;
                    ans += f(n-1-i);
                    cnt[j]++;
                }
            }
            ss.erase(ss.find(s[i]));
            cnt[ s[i] ]--;
        }
        ans++;
        printf("%10lld\n", ans);
    }



    return 0;
}

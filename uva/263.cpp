#include <bits/stdc++.h>

using namespace std;

char s[5004];

long long f(const string &s){
    long long ans = 0, b = 1;
    for(int i = s.size()-1; i >= 0; i--, b *= 10)
        ans += (s[i]-'0')*b;
    return ans;
}

int main(){

    while(scanf(" %s", s) == 1 && strcmp(s, "0")){
        printf("Original number was %s\n", s);
        string ss = s, tmp = s;
        set<string> sss;
    
        sss.insert(s);
        while(1){
            tmp = ss;
            sort(ss.begin(), ss.end());
            sort(tmp.rbegin(), tmp.rend());
            string ns = to_string(f(tmp) - f(ss));
            printf("%lld - %lld = %lld\n", f(tmp), f(ss), f(ns));
            if(sss.count(ns)) break;
            sss.insert(ns);
            ss = ns;
        }
        printf("Chain length %d\n\n", int(sss.size()));
    }



    return 0;
}

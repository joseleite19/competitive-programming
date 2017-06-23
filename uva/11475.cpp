#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string a){
    string s = a;
    reverse(s.begin(), s.end());
    s += '$';
    s += a;
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;
    for(int i = 1; i < n; i++){
        if(i <= R) z[i] = min(z[i - L], R - i + 1);
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) z[i]++;
        if(R < i + z[i] - 1) L = i, R = i + z[i] - 1;
    }
    return z;
}

const int N = 100005;
char s[N];

int main(){

    while(scanf("%s", s) == 1){
        int n = strlen(s);
        vector<int> z = z_function(s);

        int ans = n;
        for(int i = n+1; i < z.size(); i++){
            if(z[i] < z.size() - i) continue;
            ans = i - n - 1;
            break;
        }
        printf("%s", s);
        for(int i = ans-1; i >= 0; i--) printf("%c", s[i]);
        printf("\n");
    }

}

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

char s[N];
int n;

bool palin(){
    for(int i = 0; i < n / 2; i++)
        if(s[i] != s[n-1-i])
            return false;
    return true;
}

vector<int> z_function(const string &s) {
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

bool pre[N], suf[N];

bool alim(){
    string x = s; reverse(x.begin(), x.end());
    vector<int> z = z_function(x + '$' + s);
    vector<int> zz= z_function(s +('$' + x));
    
    for(int i = n+1; i < z.size(); i++){
        pre[i-n-1] = z[i] == z.size() - i;
    }
    for(int i = n+1; i <zz.size(); i++){
        suf[2*n-i] = zz[i] == zz.size()-i;
    }
    for(int i = 0; i+1 < n; i++)
        if(pre[i+1] && suf[i])
            return true;
    return false;
}

int main(){

    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        scanf(" %s", s);

        n = strlen(s);

        if(alim()) printf("alindrome\n");
        else if(palin()) printf("palindrome\n");
        else printf("simple\n");
    }

    return 0;
}

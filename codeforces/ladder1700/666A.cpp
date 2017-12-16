#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

char s[N];
int n;

set<string> vis[N];

set<string> ss;

void f(int i, const string& last){
    if(vis[i].count(last)) return;
    vis[i].insert(last);
    
    if(i - 2 >= 4){
        string tmp = "";
        tmp += s[i-1];
        tmp += s[i];
        if(tmp != last){
            ss.insert(tmp);
            f(i-2, tmp);
        }
    }
    if(i - 3 >= 4){
        string tmp = "";
        tmp += s[i-2];
        tmp += s[i-1];
        tmp += s[i];
        if(tmp != last){
            ss.insert(tmp);

            f(i-3, tmp);
        }
    }
}

int main(){

    scanf(" %s", s);

    n = strlen(s);

    f(n-1, "");

    printf("%d\n", ss.size());

    for(string x : ss)
        printf("%s\n", x.c_str());

    return 0;
}

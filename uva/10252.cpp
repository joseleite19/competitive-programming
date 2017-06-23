#include <bits/stdc++.h>

using namespace std;

char s[10004], t[10004];

int main(){

    while(scanf("%[^\n]", s) != EOF){
        getchar();
        scanf("%[^\n]", t);getchar();
        multiset<char> c, ans;
        for(int i = 0; s[i]; i++) c.insert(s[i]);
        for(int i = 0; t[i]; i++) if(c.count(t[i])){
            c.erase(c.find(t[i]));
            ans.insert(t[i]);
        }
        for(char x : ans) printf("%c", x);
        printf("\n");
        s[0] = t[0] = 0;
    }
}

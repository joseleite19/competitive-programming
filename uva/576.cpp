#include <bits/stdc++.h>

using namespace std;

bool vowel(char c){
    switch(c){ case 'a': case 'e': case 'i': case 'o' : case 'u': case 'y':
        return true;
    }
    return false;
}

char a[333], b[333], c[333];

int cnt(char *s){
    int ans = 0;
    for(int i = 0; s[i]; i++){
        if(vowel(s[i])){
            while(s[i] && vowel(s[i])) i++;
            i--;
            ans++;
        }
    }

    return ans;
}

int main(){

    while(scanf(" %[^/]/%[^/]/%[^\n]", a, b, c) == 3){
        if(!strcmp(a, "e") && !strcmp(b, "o") && !strcmp(c, "i")) break;
        
        if(cnt(a) != 5){ printf("1\n"); continue; }
        if(cnt(b) != 7){ printf("2\n"); continue; }
        if(cnt(c) != 5){ printf("3\n"); continue; }
        printf("Y\n");
    }

    return 0;
}

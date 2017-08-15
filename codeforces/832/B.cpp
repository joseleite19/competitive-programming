#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool good[256];

char s[N], t[N];
int n, m;

bool match;

int go(){
    int i, j;
    for(i = 0, j = 0; i < n && j < m; i++, j++){
        if(s[i] == '?'){
            if(!good[ t[j] ]){
                match = false;
                return j;
            }
        }
        else if(s[i] == '*'){
            return j;
        }
        else if(s[i] != t[j]){
            match = false;
            return j;
        }
    }
    if(i < n && s[i] != '*') match = false;
    return m;
}

int back(){
    int i, j;
    for(i = n-1, j = m-1; i >= 0 && j >= 0; i--, j--){
        if(s[i] == '?'){
            if(!good[ t[j] ]){
                match = false;
                return j;
            }
        }
        else if(s[i] == '*'){
            return j;
        }
        else if(s[i] != t[j]){
            match = false;
            return j;
        }
    }
    if(i >= 0 && s[i] != '*') match = false;
    return -1;
}


int main(){

    scanf(" %s", s);

    for(int i = 0; s[i]; i++){
        good[ s[i] ] = true;
    }

    scanf(" %s", s);
    bool has = false;

    n = strlen(s);

    for(int i = 0; i < n; i++) if(s[i] == '*')
        has = true;

    int q;
    scanf("%d", &q);

    while(q--){
        scanf(" %s", t);
        m = strlen(t);
        
        match = true;
        if(has){
            int lo = go(), hi = back();
            if(hi+1 < lo){
                match = false;
            }
            for(; lo <= hi; lo++) if(good[ t[lo] ]) match = false;
        }
        else if(m != n || go() != m) match = false;

        printf("%s\n", match ? "YES" : "NO");

    
    }

}

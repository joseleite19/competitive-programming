#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

struct pessoa{
    string name;
    vector<int> c;
    bool operator<(const pessoa & o) const{
        for(int i = 0; i < c.size() || i < o.c.size(); i++){
            int q = 2, w = 2;
            if(i < c.size()) q = c[i];
            if(i < o.c.size()) w = o.c[i];
            if(q != w) return q < w;            
        }
        return name < o.name;
    }
}p[N];

char s[N];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){    
        scanf(" %s", s);
        s[strlen(s)-1] = 0;

        p[i].name = s;
        while(1){
            scanf(" %s", s);
            if(s[0] == 'c') break;
            if(s[0] == 'u') p[i].c.push_back(1);
            if(s[0] == 'm') p[i].c.push_back(2);
            if(s[0] == 'l') p[i].c.push_back(3);
        }
        reverse(p[i].c.begin(), p[i].c.end());
    }

    sort(p, p+n);

    for(int i = 0; i < n; i++)
        printf("%s\n", p[i].name.c_str());


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

char s[100005];
char t[100005];
int main(){

    while(gets(t) && strcmp(t, "*")){
        s[0] = 0;
        sscanf(t, " %[^\n]", s);
        bool can = true;
        int n = strlen(s);

        for(int i = n-1; i >= 0; i--)
            if(s[i] != ' '){
                n = i+1;
                s[n] = 0;
                break;
            }

        bool dec = true, pont = false, dot = false;
        for(int i = 0; i < n; i++){
            if(s[i] == ' ') can = false;
            else if(s[i] == 'e' || s[i] == 'E'){
                if(i == 0 || i == n-1 || !dec) can = false;
                if(i > 0 && !isdigit(s[i-1])) can = false;
                pont = true;
                dec = false;
            }
            else if(s[i] == '.'){
                pont = true;
                if(dot) can = false;
                dot = true;
                if(i == 0 || i == n-1 || !isdigit(s[i-1]) || !isdigit(s[i+1]) || !dec)
                        can = false;
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(i > 0){
                    if(s[i-1] != 'e' && s[i-1] != 'E') can = false;
                    else if(i == n-1) can = false;
                }
            }
            else if(!isdigit(s[i])){
                can = false;
            }
        }
        if(!pont) can = false;

        printf("%s is %s.\n", s, can ? "legal" : "illegal");
        t[0] = 0;
    }

    return 0;
}

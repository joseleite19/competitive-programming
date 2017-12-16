#include <bits/stdc++.h>

using namespace std;

char invert(char c){
    if(c == '*') return '+';
    if(c == '+') return '*';
    if('a' <= c && c <= 'z') return c - 'a' + 'A';
    if('A' <= c && c <= 'Z') return c - 'A' + 'a';
    return c;
}

int main(){
    char formula[300];

    scanf("%s", formula);

    int level = 0;

    for(int i = 0; formula[i]; i++){
        if(formula[i] == '['){
            level++;
            formula[i] = '(';
        }
        else if(formula[i] == ']'){
            level--;
            formula[i] = ')';
        }
        else if(level & 1) formula[i] = invert(formula[i]);
    }

    printf("%s\n", formula);

    return 0;
}
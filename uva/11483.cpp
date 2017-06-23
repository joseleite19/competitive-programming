#include <bits/stdc++.h>

using namespace std;

char s[200];

int main(){

    int n;

    for(int tc = 1; scanf("%d", &n) == 1 && n; tc++){
        printf("Case %d:\n", tc);

        printf("#include<string.h>\n");
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");

        for(int i = 0; i < n; i++){
            scanf(" %[^\n]", s);
            printf("printf(\"");

            for(int j = 0; s[j]; j++){
                if(s[j] == '\"' || s[j] == '\\') printf("\\");
                printf("%c", s[j]);
            }

            printf("\\n\");\n");
        }

        printf("printf(\"\\n\");\n");
        printf("return 0;\n");
        printf("}\n");

    }



    return 0;
}

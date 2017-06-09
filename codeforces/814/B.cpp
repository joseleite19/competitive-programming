#include <bits/stdc++.h>

using namespace std;

int n, k, a[2000], b[2000];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    for(int i = 0; i < n; i++)
        scanf("%d", b+i);

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    int p1, p2, p3, p4;
    p1 = p2 = p3 = p4 = -1;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] == a[j]){
                p1 = i, p2 = j;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(b[i] == b[j]){
                p3 = i, p4 = j;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) s.erase(a[i]);

        int t = *s.begin();
        int c1 = 0, c2 = 0;
        int tmp = a[p1];
        a[p1] = t;


        for(int i = 0; i < n; i++)
            c1 += (a[i] != b[i]);

        a[p1] = tmp;
        tmp = a[p2];
        a[p2] = t;

        for(int i = 0; i < n; i++)
            c2 += (a[i] != b[i]);

        a[p2] = tmp;

        if(c1 < c2) a[p1] = t;
        else a[p2] = t;

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    









    return 0;
}

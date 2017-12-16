#include <bits/stdc++.h>

using namespace std;

void file(){
    freopen("a.in", "r", stdin);
}

int main(){
    file();
    
    int n;

    scanf("%d", &n);

    set <int> negativo;

    int v[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        if(v[i] < 0) negativo.insert(i);
    }

    int resp = 0;

    while(negativo.size() > 0){

        int pos = *negativo.begin();
        negativo.erase(pos);

        resp++;

        v[pos] = abs(v[pos]);

        if(pos == 0){
            v[pos+1] -= v[pos];
            v[n-1] -= v[pos];
            if(v[pos+1] < 0) negativo.insert(pos+1);
            if(v[n-1] < 0) negativo.insert(n-1); 
        }
        else if(pos == n-1){
            v[pos-1] -= v[pos];
            v[0] -= v[pos];
            if(v[pos-1] < 0) negativo.insert(pos-1);
            if(v[0] < 0) negativo.insert(0);
        }
        else{
            v[pos-1] -= v[pos];
            v[pos+1] -= v[pos];
            if(v[pos-1] < 0) negativo.insert(pos-1);
            if(v[pos+1] < 0) negativo.insert(pos+1);
        }
    }

    printf("%d\n",resp );

    return 0;
}

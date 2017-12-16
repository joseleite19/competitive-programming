#include <bits/stdc++.h>



#define ff first

#define ss second

#define mp make_pair



using namespace std;



const int N = 100005;



int v[N], id[N];



int ft[N];



int add(int x, int v){

        for(; x < N; x += x & -x)

                    ft[x] += v;

}



int query(int x){

        int ans = 0;

            for(; x > 0; x -= x & -x)

                        ans += ft[x];

                return ans;

}



int query(int i, int j){

        return query(j) - query(i-1);

}



int main(){



    int n;



    scanf("%d", &n);



    for(int i = 1; i <= n; i++)

        scanf("%d", v+i);



    for(int i = 1; i <= n; i++)

        id[i] = i, add(i, 1);



    sort(id+1, id+1+n, [=](int a, int b){

            if(v[a] == v[b]) return a < b;

            return v[a] < v[b];

            });



    int ans = 0;



    for(int i = 0; i < n; i++){

        ans += query(id[i]+1, n+1);

        add(id[i], -1);

    }



    printf("%d\n", ans+1);









    return 0;

}

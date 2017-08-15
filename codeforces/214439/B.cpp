#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(){

    scanf("%d %d", &n, &k);

    vector<int> ans;

    for(int i = 2; i <= n && ans.size() < k-1; i++){
        if(n % i == 0){
            while(n % i == 0 && ans.size() < k-1) n /= i, ans.push_back(i);
        }
    }

    if(n > 1) ans.push_back(n);

    if(ans.size() != k) printf("-1\n");
    else for(int i = 0; i < k; i++) printf("%d ", ans[i]);


    return 0;
}

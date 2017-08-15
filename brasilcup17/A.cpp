#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, k, v[N];

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    multiset<int> s;
    for(size_t i = 0; i < k; i++) s.insert(v[i]);
    
    multiset<int>::iterator it = s.begin(), tmp;
    for(size_t i = 0; i < s.size()/2; i++) it++;

    int ans = *it;

    for(size_t i = k; i < n; i++){ // insert i; remove i - k
        s.insert(v[i]);
        if(v[i] < *it) it--;
        if(v[i-k] <= *it) it++;
        s.erase(s.find(v[i-k]));

        ans = max(ans, *it);
    }

    printf("%d\n", ans);

    return 0;
}

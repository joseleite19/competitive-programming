#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

int n;
long long v[N];

long long L[N], R[N];

long long f(){
    long long ans = 0;
    
    stack<int> s;

    for(int i = 0; i < n; i++){
        while(!s.empty() && v[s.top()] <= v[i]){
            //do
            R[s.top()] = i-1 - s.top();

            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        //do
        R[s.top()] = n-1 - s.top();
        s.pop();
    }

    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && v[s.top()] < v[i]){
            L[s.top()] = s.top() - i-1;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        L[s.top()] = s.top();
        s.pop();
    }

    for(int i = 0; i < n; i++)
        ans += v[i] * (R[i] + 1) * (L[i] + 1);

    return ans;
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    long long ans = f();

    for(int i = 0; i < n; i++) v[i] *= -1;
    ans += f();
    /*for(int i = 0; i < n; i++)
        printf("%lld %lld\n", L[i], R[i]);*/
    printf("%lld\n", ans);



    return 0;
}

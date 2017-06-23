#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
long long v[N];

long long L[N], R[N];

long long ans[N];

void f(){
    
    stack<int> s;

    for(int i = 0; i < n; i++){
        while(!s.empty() && v[s.top()] > v[i]){
            R[s.top()] = i-1 - s.top();
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        R[s.top()] = n-1 - s.top();
        s.pop();
    }

    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && v[s.top()] > v[i]){
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
        ans[ L[i] + R[i] + 1 ] = max(ans[ L[i]+R[i]+1 ], v[i]);
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    f();

    for(int i = n; i >= 1; i--)
        ans[i] = max(ans[i], ans[i+1]);


    for(int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    printf("\n");


    return 0;
}

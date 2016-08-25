#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int f(int x){
  return (a*(((long long)x*x)%n) + b) % n;
}

int floyd(){
  int x0 = 1;
  int h = x0, t = x0;
  do{
    h = f(f(h));
    t = f(t);
  }while(h != t);
  h = x0;
  int mu = 0;
  while(h != t){
    h = f(h);
    t = f(t);
    mu++;
  }
  int lambda = 1;
  h = f(t);
  while(h != t){
    h = f(h);
    lambda++;
  }
  return lambda;
}

int main(){
  
  while(scanf("%d", &n) == 1 && n){
    scanf("%d %d", &a, &b);
    printf("%d\n", n - floyd());
  }
  
  return 0;
}

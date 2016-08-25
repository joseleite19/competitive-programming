#include <bits/stdc++.h>

using namespace std;

int z, i, m, l;

int f(int x){
  return ((z%m)*(x%m) + i) % m;
}

int floyd(){
  int h = l, t = l;
  do{
    h = f(f(h));
    t = f(t);
//   printf("%d %d\n", t, h);
  }while(h != t);
  h = l;
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
  
  for(int tc = 1; scanf("%d %d %d %d", &z, &i, &m, &l) == 4 && z+i+m+l; tc++){
    printf("Case %d: %d\n", tc, floyd());
  }
  
  return 0;
}

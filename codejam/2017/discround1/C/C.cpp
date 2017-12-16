#include <message.h>
#include <cassert>
#include <cstdio>
#include "weird_editor.h"

#define MOD (1000000007)

long long n, nodes, id;

long long exp(long long b, long long e){
  long long ans = 1;
  while(e){
    if(e & 1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}

long long f(long long num, long long qnt){
  if(qnt == 0) return 0;
  if(qnt == 1) return num;
  long long ret;
  if(qnt % 2 == 0){
    long long tmp = f(num, qnt / 2);
    ret = tmp * exp(10, qnt / 2) % MOD;
    ret = (ret + tmp) % MOD;
  }
  else{
    ret = (f(num, qnt-1) * 10) % MOD;
    ret = (ret + num) % MOD;
  }
  return ret;
}

int main(){
  n = GetNumberLength();
  nodes = NumberOfNodes();
  id = MyNodeId();
  long long l, r;

  long long qnt = (n + nodes - 1) / nodes, tmp;
  l = id*qnt;
  r = (id+1)*qnt;
  long long cnt[10];
  for(int i = 0; i < 10; i++) cnt[i] = 0;

  for(; l < n && l < r; l++){
    tmp = GetDigit(l);
    cnt[tmp]++;
    for(tmp--; tmp >= 0; tmp--)
      cnt[tmp] = 0;
  }

  long long q[10];
  for(int i = 0; i < 10; i++) q[i] = 0; 

  if(id > 0){
    Receive(id-1);
    for(int i = 0; i < 10; i++)
      q[i] = GetLL(id-1);
    for(int i = 9; i >= 0; i--){
      if(cnt[i]){
        cnt[i] += q[i];
        break;
      }
      else cnt[i] += q[i];
    }
  }

  if(id < nodes-1){ //manda pro prox
    for(int i = 0; i < 10; i++)
      PutLL(id+1, cnt[i]);
    Send(id+1);
  }
  else{
    long long sz = 0;
    long long ans = 0;
    for(int i = 9; i >= 0; i--){
      sz += cnt[i];
      ans = (ans * exp(10, cnt[i])) % MOD;
      ans = (ans + f(i, cnt[i])) % MOD;
    }
    ans = (ans * exp(10, n - sz)) % MOD;

    printf("%lld\n", ans);
  }

  return 0;
}
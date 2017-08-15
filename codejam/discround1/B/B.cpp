#include <message.h>
#include <cassert>
#include <cstdio>
#include "pancakes.h"

long long sz, n, nodes, id;

int main(){
  n = GetNumDiners();
  sz = GetStackSize();
  nodes = NumberOfNodes();
  id = MyNodeId();
  long long l, r;

  long long qnt = (sz + nodes - 1) / nodes;
  l = id*qnt;
  r = (id+1)*qnt;

  long long first = -1, last = -1, tmp, sum = 0;

  for(; l < sz && l < r; l++){
    tmp = GetStackItem(l);
    if(first == -1){
      first = last = tmp;
    }
    else{
      if(tmp < last) sum++;
      last = tmp;
    }
  }

  if(id > 0){
    Receive(id-1);
    sum += GetLL(id-1); //sum
    tmp = GetLL(id-1);
    if(first != -1 && first < tmp) //last
      sum++;
  }
  if(id < nodes-1){ //manda pro prox
    PutLL(id+1, sum);
    PutLL(id+1, last);
    Send(id+1);
  }
  else{
    printf("%lld\n", sum+1);
  }

  return 0;
}
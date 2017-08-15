
void Send(long long i){

}

void PutLL(long long i, long long j){

}

long long MyNodeId(){
	return 1;
}

long long NumberOfNodes(){
	return 2;
}

void Receive(long long i){

}

long long GetNumberLength() {
  return 10LL;
}

long long GetDigit(long long i) {
  switch ((int)i) {
    case 0: return 4LL;
    case 1: return 4LL;
    case 2: return 3LL;
    case 3: return 3LL;
    case 4: return 2LL;
    case 5: return 1LL;
    case 6: return 0LL;
    case 7: return 0LL;
    case 8: return 0LL;
    case 9: return 9LL;
    default: assert(0);
  }
}

int sz = -1;

long long GetLL(long long i){
	sz++;
	switch (sz) {
		case 0: return 0LL;
		case 1: return 0LL;
		case 2: return 1LL;
		case 3: return 2LL;
		case 4: return 2LL;
		case 5: return 0LL;
		case 6: return 0LL;
		case 7: return 0LL;
		case 8: return 0LL;
		case 9: return 0LL;
		default: assert(0);
	}
}
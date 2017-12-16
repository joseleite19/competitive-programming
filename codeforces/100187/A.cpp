#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int main(){

	int n,k;

	scanf("%d %d", &n, &k);

	if(n == 1){
		printf("0\n");
		return 0;
	}

	if(n <= k) printf("-1\n");
	else{
		printf("%d\n",((n-1)+(k-1))/k);
	}

    return 0;
}

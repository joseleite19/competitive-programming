#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(){
	file();

	int n, a, b;

	scanf("%d %d %d", &n, &a, &b);

	int q1 = 0,q2 = 0,t1 = 0, t2 = 0, qnt = 0;


	int t = 0;
	priority_queue<pair<int, int> > pq; // tempo, quem;

	for(; 1; ){
		if(t && t % a == 0){
			qnt++;
			// if(qnt < n){
				q1++;
				t1 += a;
			// }			
		}
		if(t && t % b == 0){
				qnt++;
			// if(qnt < n){
				t2 += b;
			// }
		}
		if(qnt >= n) break;
		// printf("..%d\n", t);

		t = min(t1+a, t2+b);
	}

	// printf("%d %d %d\n", t1, t2, t);
	if(t1 < t) qnt++, t1 += a;
	if(t2 < t) qnt++, t2 += b;
	t = max(t2, t1);

	printf("%d %d\n", qnt, t);





	return 0;
}
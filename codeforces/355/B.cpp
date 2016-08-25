#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, h, k, v[100005], processor, seconds;

	scanf("%d %d %d", &n, &h, &k);


	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	processor = 0;
	seconds = 0;
	for(int i = 0; i < n;){
		if(processor + v[i] <= h){
			processor += v[i];
			i++;
		}
		else{
			int tmp = (- h + processor + v[i]);

			int x = tmp/k + (tmp % k ? 1 : 0);

			processor = max(0, processor - x*k);
			seconds += x;
		}
		// break;
	}
	if(processor){
		seconds += (processor / k) + ((processor % k) != 0);
	}
		printf("%d\n", seconds);
	
	return 0;
}
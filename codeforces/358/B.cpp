#include <bits/stdc++.h>

using namespace std;


int main(){
	int n, a[100005];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);

	int mex = 1;

	for(int i = 0; i < n; i++)
		if(a[i] >= mex)
			mex++;

	printf("%d\n", mex);

	return 0;
}
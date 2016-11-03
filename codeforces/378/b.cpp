#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[100005], b[100000], n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d", a+i, b+i);

	int cnt1, cnt2;

	cnt1 = cnt2 = 0;

	for(int i = 0; i < n; i++){
		cnt1 += a[i];
		cnt2 += b[i];
	}

	int beauty = abs(cnt1 - cnt2);

	int ans = 0;

	for(int i = 0; i < n; i++){
		cnt1 = cnt1 - a[i] + b[i];
		cnt2 = cnt2 - b[i] + a[i];

		int tmp = abs(cnt1 - cnt2);
		if(tmp > beauty){
			beauty = tmp;
			ans = i+1;
		}
		
		cnt1 = cnt1 + a[i] - b[i];
		cnt2 = cnt2 + b[i] - a[i];
	}

	printf("%d\n", ans);
}
#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, a[200], b[200], cnt[10];

int tmp[10];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", a+i);
		cnt[ a[i] ]++;
	}

	for(int i = 0; i < n; i++){
		scanf("%d", b+i);
		cnt[ b[i] ]++;
	}

	for(int i = 1; i <= 5; i++)
		if(cnt[i] & 1){
			printf("-1\n");
			return 0;
		}

	int ans = 0;

	for(int i = 0; i < n; i++){
		tmp[ a[i] ]++;
		if(tmp[ a[i] ] > cnt[ a[i] ]/2)
			ans++;
	}

	for(int i = 0; i < 10; i++) tmp[i] = 0;


	for(int i = 0; i < n; i++){
		tmp[ b[i] ]++;
		if(tmp[ b[i] ] > cnt[ b[i] ]/2)
			ans++;
	}

	printf("%d\n", ans/2);


	

	return 0;
}
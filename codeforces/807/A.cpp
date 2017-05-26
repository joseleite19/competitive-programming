#include <bits/stdc++.h>

using namespace std;

int n, a[2000], b[2000];
int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d", a+i, b+i);

	bool rated = true, unrated = true;

	for(int i = 0; i < n; i++){
		if(a[i] != b[i])
			rated = true, unrated = false;
	}

	if(unrated){
		for(int i = 0; i+1 < n; i++){
			if(a[i] < a[i+1]){
				rated = false, unrated = true;
			}
		}
	}

	if(rated && unrated) printf("maybe\n");
	else if(rated) printf("rated\n");
	else printf("unrated\n");


	return 0;
}
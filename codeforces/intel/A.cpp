#include <bits/stdc++.h>

int main(){
	int h, d, n;

	scanf("%d %d:%d", &n, &h, &d);

	if(n == 12){
		if(h > 12){
			if(h % 10) h %= 10;
			else h = 10;
		}
		if(!h) h++;
	}
	else{
		if(h >= 24){
			if(h % 10) h %= 10;
			else h = 10;
		}
	}
	if(d >= 60){
		if(d % 10) d %= 10;
		else d = 10;
	}

	printf("%02d:%02d\n", h, d);

	return 0;
}
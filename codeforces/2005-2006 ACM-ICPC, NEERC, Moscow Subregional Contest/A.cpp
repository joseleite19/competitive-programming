/* Anti factorial */

#include <cstdio>
#include <cstring>

struct bignum{
	int v[500];
	int length;

	bignum(int value = 0){
		memset(v, 0, sizeof v);
		int i;
		for(i = 0; value; i++, value /= 10)
			v[i] = value % 10;
		length = i;
	}
	bignum(char * s){
		memset(v, 0, sizeof v);
		int n;
		for(n = 0; s[n]; n++);
		for(int i = 0; i < n; i++)
			v[i] = s[n-i-1]-'0';
		length = n;
	}

	void operator/=(int n) {
		int carry = 0, nextCarry;
		for(int i = length-1; i >= 0; i--){
			nextCarry = (carry*10 + v[i]) % n;
			v[i] = (carry*10 + v[i]) / n;
			carry = nextCarry;

			if(i == length-1 && v[i] == 0) length--;
		}
	}
	bool isOne(){
		if(length == 1 && v[0] == 1) return true;
		return false;
	}
	void show(){
		for(int i = length-1; i >= 0; i--)
			printf("%d", v[i]);
	}
};

int main(){
	int n;
	char number[256];
	scanf("%s", number);
	bignum bg(number);

	n = 1;
	while(!bg.isOne()){
		n++;
		bg /= n;
	}
	printf("%d\n", n);

	return 0;
}
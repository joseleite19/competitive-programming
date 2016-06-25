#include <cstdio>

int marreco(int a){
    int m, i = 0;
    while(a){
    	m = 0;
    	while(a > 4){
    	    a -= 3;
    	    m++;
    	}
	    m += a / 2;
	    i += m;
	    a = m;
    }
    return i;
}

int main(){
    int n;
    
    while(scanf("%d",&n), n)
	    printf("%d\n",marreco(n));

    return 0;
}

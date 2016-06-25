#include <stdio.h>
  
int main(){
    int n, i, por4, impar, par, tres, f, b;
    bool first = true;
      
    char ano[1005];
      
    while(scanf(" %s",ano) == 1){
        impar = par = tres = f = b = por4 = 0;
        if(!first) printf("\n");
        first = false;
	
        for(i=0; ano[i]; i++){
            tres += ano[i]-'0';
            if(i & 1)
                impar += ano[i]-'0';
            else
                par += ano[i]-'0';
        }
        n = i;
        por4 = ano[n-1]-'0' + (ano[n-2]-'0') * 10;
        if(por4 == 0){
            if((ano[n-3]-'0' + (ano[n-4]-'0')*10) % 4 == 0){
                printf("This is leap year.\n");
                b = 1;
                f = 1;
            }
	    }
        else if(por4 % 4 == 0){
            printf("This is leap year.\n");
            b = 1;
            f = 1;
        }
        if((ano[n-1]-'0') % 5 == 0){
    	    if(tres % 3 == 0){
        		printf("This is huluculu festival year.\n");
        		f = 1;
    	    }
    	    if(b && (impar-par)%11==0){
        		printf("This is bulukulu festival year.\n");
        		f = 1;
    	    }
	    }
        if(f == 0)
            printf("This is an ordinary year.\n");
    }
      
    return 0;
}
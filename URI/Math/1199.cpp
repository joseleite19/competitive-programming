#include <cstdio>

int main(){
    char num[40];
    
    for(scanf(" %s",num); num[0] != '-'; scanf(" %s",num)){
        if(strcmp(num,"0x80000000") == 0 || strcmp(num,"0X80000000") == 0)
            printf("2147483648\n");
        else if(num[1] == 'x' || num[1] == 'X')
            printf("%ld\n", strtol(num, NULL, 16));
 
        else
            printf("0x%X\n", atoi(num));
    }
    return 0;
}
#include <cstdio>
#include <vector>

int main(){
    int t, c;
    std::vector<int> v = {3, 5, 17, 257, 65537};

    scanf("%d",&t);
    while(t--){
        scanf("%d", &c);

        for(int i = 0; i < v.size(); i++)
            if(c % v[i] == 0)
                c /= v[i];
        
        while(c % 2 == 0)
            c /= 2;
     
        if(c == 1) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
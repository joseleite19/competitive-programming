#include <cstdio>
#include <cmath>

int main(){
    int a, b, c;
    double p, amarelo, triangulo, vermelho;

    while(scanf(" %d %d %d",&a, &b, &c) == 3){
        p = (a + b + c) / 2.0;
        
        triangulo = sqrt(p * (p-a) * (p-b) * (p-c));
        
        amarelo = M_PI * pow(a * b * c / triangulo / 4, 2);

        vermelho = M_PI * pow(triangulo / p, 2);

        amarelo -= triangulo;
        triangulo -= vermelho;
        printf("%.4lf %.4lf %.4lf\n", amarelo, triangulo, vermelho);
    }
}
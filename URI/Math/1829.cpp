#include <cstdio>
#include <cmath>

double logsfat[10005];

int main(){
	int n, u, a, b, i, c;
	double aux;

	scanf("%d", &n);
	int v[1005], l = 0;

	logsfat[0] = logsfat[1] = 0;

	for(i = 2; i < 10005; i++)
		logsfat[i] = logsfat[i-1] + log(i);

	for(u = 0; u < n; u++){
		aux = 0;
		scanf(" %d^%d", &a, &b);
		scanf(" %d!", &c);
		aux = b * log(a);
		if(b*log(a) - logsfat[c] > 0.001){
			v[u]=1;
			l++;
		}
		else v[u] = 0;
	}
	if(l*2 > n) printf("Campeao: Lucas!\n");
	else if(2*l < n) printf("Campeao: Pedro!\n");
	else printf("A competicao terminou empatada!\n");

	for(u = 0; u < n; u++)
		printf("Rodada #%d: %s foi o vencedor\n", u+1, v[u] ? "Lucas" : "Pedro");

	return 0;
}
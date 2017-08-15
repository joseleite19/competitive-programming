#include <bits/stdc++.h>

using namespace std;

int main(){

	int casos;

	scanf("%d", &casos);
	getchar();

	int z = 1;

	while(casos--){

		string str;

		getline(cin, str);

		stringstream in(str);

		string numero;

		vector <double> v;

		double media = 0;

		while(in >> numero){

			double val = atof(numero.c_str());

			v.push_back(val);

			media += val;
		}

		media /= (double) v.size();

		double desvio = 0;

		for(int i = 0; i < v.size(); i++){

			double l = v[i] - media;

			l *= l;

			desvio += l;
		}

		desvio /= v.size();

		desvio = sqrt(desvio);

		printf("Turma %d: media %.1lf desvio %.1lf\n",z++,media,desvio );

	}

	return 0;
}
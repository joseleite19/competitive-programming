#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

struct carros {
	string tipo;
	int preco, pegar, km;
};

struct eventos {
	int t;
	string nome;
	char c;
	string carro;
	int valor;
};

bool mycomp(eventos a, eventos b){
	return a.t < b.t;
}

int main(){
	
	int t, n, m, i;
	
	scanf(" %d", &t);
	
	while(t--){
		
		scanf(" %d %d", &n, &m);

		map <string, carros> Carros;
		
		for(i=0;i<n;i++){
			carros aux;
			cin >> aux.tipo;
			scanf(" %d %d %d", &aux.preco, &aux.pegar, &aux.km);
			Carros[aux.tipo] = aux;
		}
		
		vector<eventos> Eventos;
		
		for(i=0;i<m;i++){
			eventos aux;
			scanf(" %d", &aux.t);
			cin >> aux.nome;
			scanf(" %c", &aux.c);
			if(aux.c=='p'){
				cin >> aux.carro;
			}
			else
				scanf(" %d", &aux.valor);
			Eventos.push_back(aux);
		}
		
		sort(Eventos.begin(), Eventos.end(), mycomp);
		
		map<string, pair<string,bool>> espioes;
		
		map <string,int> pagar;

		for(auto x: Eventos){
			
			string nome_espiao = x.nome;

			char ocorreu = x.c;

			if(ocorreu == 'p'){

				string carro = x.carro;

				if(espioes.count(nome_espiao) == 0 or espioes[nome_espiao].second == false){
					espioes[nome_espiao].first = carro;
					espioes[nome_espiao].second = true;
					if(pagar[nome_espiao] != -1){
						pagar[nome_espiao] += Carros[carro].pegar;
					}
				}
				else if(espioes[nome_espiao].second == true){
					pagar[nome_espiao] = -1;
				}
				else{
					if(pagar[nome_espiao] != -1){
						espioes[nome_espiao].first = carro;
						espioes[nome_espiao].second = true;
						pagar[nome_espiao] += Carros[carro].pegar;
					}	
				}
			}
			else if(ocorreu == 'r'){

				int km = x.valor;

				if(espioes.count(nome_espiao) == 0 or espioes[nome_espiao].second == false){
					pagar[nome_espiao] = -1;
				}
				else{
					espioes[nome_espiao].second = false;
					if(pagar[nome_espiao] != -1){
						pagar[nome_espiao] += km* Carros[espioes[nome_espiao].first].km;
					}
				}
			}
			else{

				int perc = x.valor;

				if(espioes.count(nome_espiao) == 0 or espioes[nome_espiao].second == false){
					pagar[nome_espiao] = -1;
				}
				else{
					if(pagar[nome_espiao] != -1){
						pagar[nome_espiao] += ((perc*Carros[espioes[nome_espiao].first].preco+99 )/100);
					}
				}

			}
		}

		for(auto x: espioes){
			if(x.second.second == true){
				pagar[x.first] = -1;
			}
		}

		for(auto x: pagar){
			cout << x.first << " ";
			if(x.second == -1){
				cout << "INCONSISTENT" << endl;	
			}
			else cout << x.second << endl;
		}

	};
	return 0;
}
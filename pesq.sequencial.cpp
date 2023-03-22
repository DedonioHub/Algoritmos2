#include <iostream>
using namespace std;

int main()
{
	int vetor[100];//vetor de dados
	int numero;//numero de entrada
	int procurado;//elemento a ser procurado
	int i;//contador
	bool achou;//indica se o elemento procurado foi encontrado no vetor
	int posicao;//posicao no vetor do elemento procurado
	int N; // quantidade de elementos inseridos

	//Lendo elementos e inserindo no vetor
	i = 0;
	cin >> numero;
	while(numero != -1)
	{
		vetor[i] = numero;
		cin >> numero;
		i++;
	}
	N = i;

	//Lendo elemento a ser procurado
	cin >> procurado;

	//Procurando elemento no vetor (busca sequencial)
	i = 0;
	achou = false;
	while(i < N && achou == false)
	{
		if(vetor[i] == procurado)
		{
			achou = true;
			posicao = i;
		}
		i++;
	}

	//Apresentando resultado
	if(achou == true)
		cout << procurado << " encontrado na posicao " << posicao << endl;
	else
		cout << procurado << " nao encontrado" << endl;

	return 0;
}
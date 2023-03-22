#include<iostream>

using namespace std;
// funçao de ordenação bubble sort
void bubbleSort(int vetor[], int tamanho)
{
	int i, j; // contadores
	int trab;
	bool troca;
	int limite;
	int contador = 0; // contador de troca
	troca = true;
	limite = tamanho - 1;
	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)
			if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				cout << "New trab:" << trab << endl; // saida da quantidade novos trabs
				j = i;
				troca = true;
				contador++;
			}
		limite = j;
	}
	cout << "Contador:" << contador << endl;
}
int main()
{
	int vetor[100];
	int tamanho;
	int i; //contador

	cin >> tamanho;

	for(i = 0; i < tamanho; i++)
	{
		cin >> vetor[i];
	}
	bubbleSort(vetor, tamanho);

	return 0;
}
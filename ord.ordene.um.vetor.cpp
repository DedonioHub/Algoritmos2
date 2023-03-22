#include<iostream>

using namespace std;
// funçao de ordenação bubble sort
void bubbleSort(int vetor[], int tamanho)
{
    int i,j,k; // contadores
    int trab;
    bool troca;
    int limite;
    troca = true;
    limite = tamanho-1;
    while (troca)
    {
        troca = false;
	for (i=0;i<limite;i++)
	    if (vetor[i] > vetor[i+1])
	    {~
	        trab = vetor[i];
	        vetor[i] = vetor[i+1];
	        vetor[i+1] = trab;
	        j = i;
	        troca = true;
	    }
	limite = j;	
    }
}
int main()
{
	int vetor[100];
	int tamanho;
	int i = 0; // contador
	int j; // contador
	int numero;

	cin >> numero;
	while(numero != -1)
	{
		vetor[i] = numero;
		cin >> numero;
		i++;
	}
	tamanho = i;

	bubbleSort(vetor, tamanho);

	for(j = 0; j < tamanho; j++)
	{
		cout << vetor[j] << " ";
	}

	return 0;
}